#include "BaseInfos.h"

BaseInfos::BaseInfos(QObject* parent)
	: QObject(parent)
{}

QString BaseInfos::getProtocolInfo()
{
	//初始化一个info字符串
	char info[10000] = { 0 };
	avformat_network_init();
	struct URLProtocol* pup = nullptr;

	//input
	struct URLProtocol** p_temp = &pup;

	avio_enum_protocols((void**)p_temp, 0);
	while ((*p_temp) != nullptr) {
		sprintf(info, "%s[ProtocolInfo - In ][%10s]\n", info, avio_enum_protocols((void**)p_temp, 0));
	}
	pup = nullptr;

	//output

	avio_enum_protocols((void**)p_temp, 1);
	while ((*p_temp) != nullptr) {
		sprintf(info, "%s[ProtocolInfo - Out][%10s]\n", info, avio_enum_protocols((void**)p_temp, 1));
	}
	QString ret = QString::fromUtf8(info, 10000);
	return ret;
}

QString BaseInfos::getAVFormatInfo()
{
	// 初始化一个info字符串
	char info[10000] = { 0 };

	avformat_network_init();
	const AVInputFormat* input_format = nullptr;
	const AVOutputFormat* output_format = nullptr;

	// 输入
	while ((input_format = av_demuxer_iterate((void**)&input_format)) != nullptr) {
		sprintf(info, "%s[getAVFormatInfo - In ] %10s\n", info, input_format->name);
	}

	// 输出
	while ((output_format = av_muxer_iterate((void**)&output_format)) != nullptr) {
		sprintf(info, "%s[getAVFormatInfo- Out] %10s\n", info, output_format->name);
	}

	QString ret = QString::fromUtf8(info, 10000);
	return ret;


}

QString BaseInfos::getAVCodedInfo()
{
	char info[10000] = { 0 };

	avformat_network_init();

	const AVCodec* codec_temp = nullptr;
	while ((codec_temp = av_codec_iterate((void**) & codec_temp)) != nullptr) {
		const AVCodec* decoder = avcodec_find_decoder(codec_temp->id);
		if (decoder != nullptr) {
			sprintf(info, "%s[getAVCodedInfo -Dec]", info);
		}
		else {
			sprintf(info, "%s[getAVCodedInfo - Enc]", info);
		}

		switch (codec_temp->type) {
		case AVMEDIA_TYPE_VIDEO: {
			sprintf(info, "%s[getAVCodedInfo - Video]", info);
			break;
		}
		case AVMEDIA_TYPE_AUDIO: {
			sprintf(info, "%s[getAVCodedInfo - Audio]", info);
			break;
		}
		default: {
			sprintf(info, "%s[getAVCodedInfo - Other]", info);
			break;
		}
		}
	}

	return QString::fromUtf8(info);

}

QString BaseInfos::getAVFilterInfo()
{
	char info[10000] = { 0 };
	avformat_network_init();
	const AVFilter* filter = (AVFilter*)av_filter_iterate(nullptr);
	while (filter != nullptr) {
		sprintf(info, "%s[%10s]\n", info, filter->name);
	}
	QString ret = QString::fromUtf8(info);
	return ret;
}

QString BaseInfos::getConfigurationInfo()
{
	char info[10000] = { 0 };
	avformat_network_init();
	sprintf(info, "%s\n", avcodec_configuration());
	return QString::fromUtf8(info);
}

BaseInfos::~BaseInfos()
{}
