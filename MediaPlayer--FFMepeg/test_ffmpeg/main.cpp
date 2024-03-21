#include <iostream>

using namespace std;
//要引用C语言的库文件 则要加__Cpulsplus
extern "C"
{
#include <libavcodec/avcodec.h>
}
#pragma comment(lib,"avcodec.lib")//添加库文件，也可以在属性处添加
int main()
{
	//显示ffmpeg的编译配置
	cout << "Test FFmpeg " << endl;
	//getchar();
	cout << avcodec_configuration() << endl;

	system("pause");
	return 0;
}
