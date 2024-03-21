# 前言
参考了雷神的自制播放器项目，[100行代码实现最简单的基于FFMPEG+SDL的视频播放器（SDL1.x）](https://blog.csdn.net/leixiaohua1020/article/details/8652605)

不过老版本的代码参考意义不大了，我现在准备使用Qt + VS2022 + FFmpeg59重写这部分代码，具体的代码仓库如下：

[LeventureQys/MediaPlay-FFmpeg](https://github.com/LeventureQys/MediaPlay-FFmpeg)

开发环境：
Visual Studio 2022 + Qt 5.14.2 + FFmpeg 59

# 本文任务

1. 调通编译环境
2. 打印协议支持信息、AVFormat信息、AVCodec 支持信息、AVFilter信息、配置信息等
3. 提供一个通用的调试框架

# 流程
## 1. 开发环境准备

首先我们Visual Studio 2022 + qt是准备好的，这里不做过多介绍了。
这里简单说说我在做这一块的时候，为什么没有选择用雷神已经写好的代码和库来进行开发，因为老版ffmpeg对新的项目支持比较差，而且是32位的，不兼容64位的qt，而且老版本的c++兼容对新版的编译器有很多问题，所以我在多次尝试没法正常使用VS 2022 + qt完成雷神的代码编译之后就放弃了，准备用新版的ffmpeg来进行一些编写，而且实际上新版的接口更合理，不过有一些改动，需要稍微查一下。总的来说流程是一回事。

下载FFmpeg的build : [FFmpeg-Builds - Public](https://github.com/BtbN/FFmpeg-Builds)

压缩包里的内容如下：
![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/3272e2da3bd546e78b019de1a3a68413.png)
其中include是头文件，lib是链接文件，bin是dll文件

具体链接和include这里就不谈了，很简单，随便配配就行了

## 2. 具体代码
在导入头文件的时候，需要注意是以这种形式导入：

下面的#pragma comment (lib, "")  是选配的，你可以在代码中写，也可以在工程中预备配置好

需要注意的是，新版本的迭代器和老版本的不太一样，现在这个是自制了一个void*类型来作为迭代器使用的，所以需要注意！

```
//Windows
extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavfilter/avfilter.h"
};


extern "C"
{
#pragma comment (lib, "Ws2_32.lib")  
#pragma comment (lib, "avcodec.lib")
#pragma comment (lib, "avdevice.lib")
#pragma comment (lib, "avfilter.lib")
#pragma comment (lib, "avformat.lib")
#pragma comment (lib, "avutil.lib")
#pragma comment (lib, "swresample.lib")
#pragma comment (lib, "swscale.lib")
};
```
我这里做了一个BaseInfos类，内容就是返回这几个特定信息的QString内容，如下：

BaseInfo.h

```
#pragma once

#include <QObject>
/// <summary>
/// 这个类用于获得所有的ffmpeg信息
/// </summary>
/// 
#include "PublicHeader.h"
//FIX
struct URLProtocol;


class BaseInfos : public QObject
{
	Q_OBJECT

public:
	BaseInfos(QObject* parent = nullptr);

	/// <summary>
	/// 协议支持信息
	/// </summary>
	/// <returns>输入内容和输出内容</returns>
	QString getProtocolInfo();

	/// <summary>
	/// 获得AVFormat信息
	/// </summary>
	/// <returns></returns>
	QString getAVFormatInfo();

	/// <summary>
	/// 获得AVCodec 支持信息
	/// </summary>
	/// <returns></returns>
	QString getAVCodedInfo();

	/// <summary>
	/// 获得AVFilter信息
	/// </summary>
	/// <returns></returns>
	QString getAVFilterInfo();

	/// <summary>
	/// 获得配置信息
	/// </summary>
	/// <returns></returns>
	QString getConfigurationInfo();                  
	~BaseInfos();
};

```



BaseInfos.cpp

```
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
	char info[50000] = { 0 };

	avformat_network_init();

	const AVCodec* codec_temp = nullptr;
	void* opaque = nullptr;
	codec_temp = av_codec_iterate(&opaque);
	while ((codec_temp = av_codec_iterate(&opaque)) != nullptr) {
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

	return QString::fromUtf8(info,50000);

}

QString BaseInfos::getAVFilterInfo()
{
	char info[10000] = { 0 };
	avformat_network_init();
	const AVFilter* filter = nullptr;
	void* opaque = nullptr;
	filter = av_filter_iterate(&opaque);
	while ((filter = av_filter_iterate(&opaque)) != nullptr) {
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


```

## 3.效果

![在这里插入图片描述](https://img-blog.csdnimg.cn/direct/907f577e470b46b4ac076d71cea7dbee.png)

