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
