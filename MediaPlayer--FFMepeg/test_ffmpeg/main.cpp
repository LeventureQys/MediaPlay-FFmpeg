#include <iostream>

using namespace std;
//Ҫ����C���ԵĿ��ļ� ��Ҫ��__Cpulsplus
extern "C"
{
#include <libavcodec/avcodec.h>
}
#pragma comment(lib,"avcodec.lib")//��ӿ��ļ���Ҳ���������Դ����
int main()
{
	//��ʾffmpeg�ı�������
	cout << "Test FFmpeg " << endl;
	//getchar();
	cout << avcodec_configuration() << endl;

	system("pause");
	return 0;
}
