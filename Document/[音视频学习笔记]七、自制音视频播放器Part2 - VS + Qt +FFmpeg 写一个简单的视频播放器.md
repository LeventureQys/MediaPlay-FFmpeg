# 前言
话不多说，重走霄骅登神路

前一篇文章
[[音视频学习笔记]六、自制音视频播放器Part1 -新版本ffmpeg，Qt +VS2022，都什么年代了还在写传统播放器？](https://blog.csdn.net/Andius/article/details/136923005?spm=1001.2014.3001.5502)

本文相关代码仓库：
[MediaPlay-FFmpeg - Public](https://github.com/LeventureQys/MediaPlay-FFmpeg)

转载雷神的两个流程图，挺实用的，不过现在接口有一些小修改，可能有点不一样了

![在这里插入图片描述](https://img-blog.csdn.net/20140508135954718?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvbGVpeGlhb2h1YTEwMjA=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)



# 流程
1. 首先，定义了一些变量，包括用于存储视频帧的缓冲区 buf，标记是否为视频流的 isVideo，以及一些用于处理视频的结构体和指针。

2. 创建并初始化 AVFormatContext 结构体 ptr_formatCtx，并打开视频文件以获取音视频流数据信息。

3. 使用 avformat_find_stream_info 函数获取音视频流信息，并通过循环找到视频流的索引 streamIndex。

4. 检查是否成功找到视频流，判断 ptr_formatCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO 如果没有找到则退出。

5. 分配并初始化 AVCodecContext 结构体 ptr_avctx，并根据流的参数找到AVCodecParameters，将其放在ptr_formatCtx->streams[streamIndex]->codecpar。找到对应视频流的解码器avcodec_find_decoder，并检查。

6. 使用 avcodec_open2 函数打开解码器，初始化ptr_avctx，准备解码视频帧。

7. 分配并初始化 AVPacket 结构体 ptr_avpkg，以及视频帧的空间 ptr_avframe和 ptr_avframeRGB。

8. 为图像数据存储空间 buf 分配内存，并根据视频的宽高调整窗口大小。

9. 初始化 SwsContext 结构体 ptr_swsCtx，用于图像的缩放和格式转换。

10. 进入循环，不断读取视频数据帧，并解码、处理、显示。

11. 在循环中，通过 av_read_frame 读取视频帧数据，然后使用 avcodec_send_packet将数据发送给解码器进行解码，使用avcodec_receive_frame解码视频数据，并将解码后的图像数据经过格式转换后显示在界面上。

12. 循环中还包含了处理视频播放状态的逻辑，包括播放、暂停和结束播放等情况。

13. 最后，释放相关资源，包括 SwsContext 结构体、图像帧内存和解码器等。

## 需要注意的点

1. 播放延时
我们在播放的时候实际上是需要提供延时的，但是又不能直接QThread::msleep(10)，因为画面的渲染在主线程上进行，而主线程是严格禁止msleep(10)的否则容易崩溃，所以采用以下方式：

```cpp
//延时, 不能直接sleep延时，UI主线程不能直接被阻塞，不然会有问题的
void delay(int ms)
{
    QTime stopTime;
    stopTime.start();
    //qDebug()<<"start:"<<QTime::currentTime().toString("HH:mm:ss.zzz");
    while(stopTime.elapsed() < ms)//stopTime.elapsed()返回从start开始到现在的毫秒数
    {
        QCoreApplication::processEvents();
    }
    //qDebug()<<"stop :"<<QTime::currentTime().toString("HH:mm:ss.zzz");
}
```

2. 播放速度
播放速度实际上就是通过影响上述的delay来实现的，在播放的过程中通过对应的值影响延时，从而修改播放速度。

项目效果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/2afff4465b2d45218068d2b4685630f9.png)

## 核心代码

```cpp
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
	AVPacket* ptr_avpkg = nullptr;
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

	//初始化ptr_avpkg
	ptr_avpkg = (AVPacket*)av_malloc(sizeof(AVPacket));

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
			if (av_read_frame(ptr_formatCtx, ptr_avpkg) >= 0) {	//读取一帧未解码的数据
				//如果是视频数据
				if (ptr_avpkg->stream_index == (int)streamIndex) {
					// 将数据发送给解码器进行解码
					ret = avcodec_send_packet(ptr_avctx, ptr_avpkg);
					if (ret < 0) {
						qDebug() << "发送数据包到解码器时发生错误: "<<ret;
						continue; // 处理错误情况并继续读取下一帧数据
					}
					//解码视频数据
					ret = avcodec_receive_frame(ptr_avctx, ptr_avframe);
					if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
					{
						av_packet_unref(ptr_avpkg); // 释放解码后的帧数据
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

```


.
