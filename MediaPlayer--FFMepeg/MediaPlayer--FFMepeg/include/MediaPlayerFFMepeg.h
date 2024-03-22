#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MediaPlayerFFMepeg.h"
#include "../include/BaseInfos.h"
class MediaPlayerFFMepeg : public QMainWindow
{
	Q_OBJECT

public:
	MediaPlayerFFMepeg(QWidget* parent = nullptr);
	~MediaPlayerFFMepeg();
private slots:

	void on_btn_getAVFormat_clicked();
	void on_btn_getProtocol_clicked();
	void on_btn_getAVCodeInfo_clicked();
	void on_btn_getAVFilterInfo_clicked();
	void on_btn_getConfiguration_clicked();

	void Add(const QString& message);
private:
	BaseInfos* info = nullptr;
	Ui::MediaPlayerFFMepegClass ui;
};
