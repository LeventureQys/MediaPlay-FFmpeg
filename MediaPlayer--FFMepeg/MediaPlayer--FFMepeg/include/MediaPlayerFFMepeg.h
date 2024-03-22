#pragma once
#pragma execution_character_set("utf-8") 

#include <QtWidgets/QMainWindow>
#include "ui_MediaPlayerFFMepeg.h"
#include "../include/BaseInfos.h"
#include "../include/MediaPlay_Core.h"
#include "qfiledialog.h"
class MediaPlayerFFMepeg : public QMainWindow
{
	Q_OBJECT

public:
	MediaPlayerFFMepeg(QWidget* parent = nullptr);
	~MediaPlayerFFMepeg();
	//渲染函数
	void FrameRender(const uchar* data, const int width, const int height);

private slots:

	void on_btn_getAVFormat_clicked();
	void on_btn_getProtocol_clicked();
	void on_btn_getAVCodeInfo_clicked();
	void on_btn_getAVFilterInfo_clicked();
	void on_btn_getConfiguration_clicked();

	void Add(const QString& message);

	void on_btn_chooseMeadia_clicked();
	void on_btn_VideoClose_clicked();
	void on_btn_play_clicked(bool Checked);
private:
	BaseInfos* info = nullptr;
	MediaPlay_Core* core = nullptr;
	Ui::MediaPlayerFFMepegClass ui;
	QString current_file;
	qint32 delay = 60;//
	
};
