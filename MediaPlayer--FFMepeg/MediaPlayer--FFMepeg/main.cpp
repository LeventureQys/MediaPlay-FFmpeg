#include <cstdint>
#include "MediaPlayerFFMepeg.h"

#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	MediaPlayerFFMepeg w;
	w.show();
	return a.exec();
}
