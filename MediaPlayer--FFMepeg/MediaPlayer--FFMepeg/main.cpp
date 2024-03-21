#include <cstdint>
#include "MediaPlayerFFMepeg.h"

#include <QtWidgets/QApplication>
#include <stdio.h>

//Windows
extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavfilter/avfilter.h"
};
int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	MediaPlayerFFMepeg w;
	w.show();
	return a.exec();
}
