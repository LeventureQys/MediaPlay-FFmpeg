#include "BaseInfos.h"

BaseInfos::BaseInfos(QObject* parent)
	: QObject(parent)
{}

QString BaseInfos::getProtocolInfo()
{
	//初始化一个info字符串
	char info[10000] = { 0 };
	av_register_all();
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
	//初始化一个info字符串
	char info[10000] = { 0 };

	av_register_all();
	AVInputFormat* input_format = av_iformat_next(nullptr);
	AVOutputFormat* output_format = av_oformat_next(nullptr);

	//输入
	while (input_format != nullptr) {
		sprintf(info, "%s[getAVFormatInfo - In ] %10s\n", info, input_format->name);
		input_format = input_format->next;
	}

	//输出
	while (output_format != nullptr) {
		sprintf(info, "%s[getAVFormatInfo- Out] %10s\n", info, output_format->name);
		output_format = output_format->next;
	}

	QString ret = QString::fromUtf8(info, 10000);
	return ret;
}

QString BaseInfos::getAVCodedInfo()
{
	char info[10000] = { 0 };

	av_register_all();

	AVCodec* codec_temp = av_codec_next(nullptr);

	while (codec_temp != nullptr) {
		if (codec_temp->decode != nullptr) {
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


	return QString();
}

QString BaseInfos::getAVFilterInfo()
{
	char info[10000] = { 0 };
	av_register_all();
	AVFilter* filter = (AVFilter*)avfilter_next(nullptr);
	while (filter != nullptr) {
		sprintf(info, "%s[%10s]\n", info, filter->name);
	}
	QString ret = QString::fromUtf8(info);
	return ret;
}

QString BaseInfos::getConfigurationInfo()
{
	char info[10000] = { 0 };
	av_register_all();
	sprintf(info, "%s\n", avcodec_configuration());
	return QString::fromUtf8(info);
}

BaseInfos::~BaseInfos()
{}
