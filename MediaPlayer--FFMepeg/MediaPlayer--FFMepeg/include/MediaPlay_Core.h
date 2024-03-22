#pragma once

#include "../include/PublicHeader.h"
#include "qdebug.h"
#include "qtimer.h"
#include"qtimezone.h"
#include "qcoreapplication.h"
/// <summary>
/// 播放器核心，专门用于渲染得到char*的画面数据
/// </summary>
enum class PlayState {
	Video_None,
	Video_Playing,
	Video_Pause,
	Video_Finish
};


class MediaPlay_Core
{

public:
	MediaPlay_Core();
	~MediaPlay_Core();

	/// <summary>
	/// 返回单帧画面的回调函数
	/// </summary>
	using func_frame = void(*)(const uchar* data, const int width, const int height);
	void register_func(func_frame func);

	int playVideo(const char* videopath);
	void VideoPlayControl(bool blnPlay);
	void VideoPlayEnd();


private:
	func_frame callback = nullptr;
	PlayState state_playVideo;
	QString videoUrl = "";
	void delay(int msc);
};
