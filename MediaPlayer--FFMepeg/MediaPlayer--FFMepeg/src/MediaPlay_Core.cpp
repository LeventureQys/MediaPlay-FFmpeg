#include "../include/MediaPlay_Core.h"

MediaPlay_Core::MediaPlay_Core()
{

}

MediaPlay_Core::~MediaPlay_Core()
{}

void MediaPlay_Core::register_func(func_frame func)
{
	this->callback = func;
}

int MediaPlay_Core::playVideo(const char* videopath)
{
	unsigned char* buf;
	bool blnVideo = false;
	int ret, gotPicture;
	unsigned int streamIndex = 0;

	const AVCodec* ptr_codec = nullptr;
	AVPacket* ptr_avptr = nullptr;
	AVCodecContext* ptr_avctx = nullptr;
	AVFrame* ptr_avframe, * ptr_avframeRGB = nullptr;
	AVFormatContext* ptr_formatCtx = nullptr;
	struct SwsContext* ptr_swsCtx = nullptr;

	this->videoUrl = QString::fromLocal8Bit(videopath);

	int width = 0;
	int height = 0;
	//创建AVFormatContext
	ptr_formatCtx = avformat_alloc_context();

	//初始化ptr_formatCtx 
	if (avformat_open_input(&ptr_formatCtx, videopath, nullptr, nullptr) != 0) {
		qDebug() << "AVFormat open input Error";
		return -1;
	}

	//获取音频流数据信息
	if (avformat_find_stream_info(ptr_formatCtx, nullptr) < 0) {
		avformat_close_input(&ptr_formatCtx);
		qDebug() << "AVFormat find stream info Error";
		return -2;
	}

	//找到视频流的索引

	for (int i = 0; i < ptr_formatCtx->nb_streams; ++i) {
		if (ptr_formatCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
			streamIndex = i;
			blnVideo = true;
			break;
		}
	}

	//没有找到视频流则直接退出
	if (!blnVideo) {
		avformat_close_input(&ptr_formatCtx);
		qDebug() << "nv_streams error";
		return -3;
	}

	//获取视频流编码
	ptr_avctx = avcodec_alloc_context3(nullptr);

	//查找编码器
	avcodec_parameters_to_context(ptr_avctx, ptr_formatCtx->streams[streamIndex]->codecpar);
	ptr_codec = avcodec_find_decoder(ptr_avctx->codec_id);

	if (!ptr_codec) {
		avcodec_close(ptr_avctx);
		avformat_close_input(&ptr_formatCtx);
		qDebug() << "Can't find decoder";
		return -4;
	}

	//初始化ptr_avctx
	if (avcodec_open2(ptr_avctx, ptr_codec, nullptr) < 0) {
		avcodec_close(ptr_avctx);
		avformat_close_input(&ptr_formatCtx);
		qDebug() << "avcodec_open2 err.";
		return -5;
	}

	//初始化ptr_avptr
	ptr_avptr = (AVPacket*)av_malloc(sizeof(AVPacket));

	//初始化数据帧空间
	ptr_avframe = av_frame_alloc();
	ptr_avframeRGB = av_frame_alloc();

	//创建图像数据存储buf
   //av_image_get_buffer_size一帧大小
	buf = (unsigned char*)av_malloc(av_image_get_buffer_size(AV_PIX_FMT_RGB32, ptr_avctx->width, ptr_avctx->height, 1));
	av_image_fill_arrays(ptr_avframeRGB->data, ptr_avframeRGB->linesize, buf, AV_PIX_FMT_RGB32, ptr_avctx->width, ptr_avctx->height, 1);

	width = ptr_avctx->width;
	height = ptr_avctx->height;

	//初始化ptr_swsCtx
	ptr_swsCtx = sws_getContext(ptr_avctx->width, ptr_avctx->height, ptr_avctx->pix_fmt, ptr_avctx->width, ptr_avctx->height, AV_PIX_FMT_RGB32, SWS_BICUBIC, nullptr, nullptr, nullptr);

	//尝试循环读取视频数据
	while (true) {
		if (this->state_playVideo == PlayState::Video_Playing) { // 正在播放
			if (av_read_frame(ptr_formatCtx, ptr_avptr) >= 0) {	//读取一帧未解码的数据
				//如果是视频数据
				if (ptr_avptr->stream_index == (int)streamIndex) {
					// 将数据发送给解码器进行解码
					ret = avcodec_send_packet(ptr_avctx, ptr_avptr);
					if (ret < 0) {
						qDebug() << "发送数据包到解码器时发生错误: "<<ret;
						continue; // 处理错误情况并继续读取下一帧数据
					}
					//解码一的视频数据
					ret = avcodec_receive_frame(ptr_avctx, ptr_avframe);
					if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
					{
						av_packet_unref(ptr_avptr); // 释放解码后的帧数据
						continue; // 没有可解码的帧数据或者已经解码完毕，继续读取下一帧
					}
					if (ret < 0) {
						qDebug() << "Decode error";
						continue;
					}
					// 处理解码后的图像帧
					sws_scale(ptr_swsCtx, (const unsigned char* const*)ptr_avframe->data, ptr_avframe->linesize, 0, ptr_avctx->height, ptr_avframeRGB->data, ptr_avframeRGB->linesize);
					if(this->callback != nullptr)
						this->callback((uchar*)ptr_avframeRGB->data[0], width, height);

					av_frame_unref(ptr_avframe);
				}

			}
			else {
				break;
			}
		}
		else if (this->state_playVideo == PlayState::Video_Finish)//播放结束
		{
			break;
		}
		else//暂停
		{
			delay(300);
		}
	}

	//释放资源
	sws_freeContext(ptr_swsCtx);
	av_frame_free(&ptr_avframeRGB);
	av_frame_free(&ptr_avframe);
	avcodec_close(ptr_avctx);
	avformat_close_input(&ptr_formatCtx);

	this->state_playVideo = PlayState::Video_Finish;
	qDebug() << "play finish!";
	return 0;
}

void MediaPlay_Core::VideoPlayControl(bool blnPlay)
{
	if (blnPlay) {
		if (this->state_playVideo != PlayState::Video_Playing) {
			this->state_playVideo = PlayState::Video_Playing;
			playVideo(this->videoUrl.toLocal8Bit().data());
		}
		else {
			this->state_playVideo = PlayState::Video_Playing;
		}
	}
	else {
		if (this->state_playVideo == PlayState::Video_Playing) {
			this->state_playVideo = PlayState::Video_Pause;
		}
	}
}

void MediaPlay_Core::VideoPlayEnd()
{
	//停止播放视频
	this->state_playVideo = PlayState::Video_Finish;
}

void MediaPlay_Core::delay(int msc)
{
	QTime stopTime;
	stopTime.start();
	while (stopTime.elapsed() < msc)//stopTime.elapsed()返回从start开始到现在的毫秒数
	{
		QCoreApplication::processEvents();
	}
}
