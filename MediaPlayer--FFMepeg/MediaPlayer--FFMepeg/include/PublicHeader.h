#pragma once
#include <stdio.h>
#include <Windows.h>
//Windows
//包含了一些ffmpeg相关的头文件和lib文件的引用
extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavfilter/avfilter.h"
#include "libswscale/swscale.h"
#include "libavdevice/avdevice.h"
#include "libavformat/version.h"
#include "libavutil/time.h"
#include "libavutil//mathematics.h"
#include "libavutil/imgutils.h"

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