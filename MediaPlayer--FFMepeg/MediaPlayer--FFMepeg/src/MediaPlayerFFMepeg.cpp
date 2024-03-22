#include "../include/MediaPlayerFFMepeg.h"

MediaPlayerFFMepeg::MediaPlayerFFMepeg(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->info = new BaseInfos(this);
}

MediaPlayerFFMepeg::~MediaPlayerFFMepeg()
{}

void MediaPlayerFFMepeg::on_btn_getProtocol_clicked()
{
	QString ret = this->info->getProtocolInfo();
	this->Add(ret);
}

void MediaPlayerFFMepeg::on_btn_getAVCodeInfo_clicked()
{
	QString ret = this->info->getAVCodedInfo();
	this->Add(ret);
}

void MediaPlayerFFMepeg::on_btn_getAVFilterInfo_clicked()
{
	QString ret = this->info->getAVFilterInfo();
	this->Add(ret);
}

void MediaPlayerFFMepeg::on_btn_getConfiguration_clicked()
{
	QString ret = this->info->getConfigurationInfo();
	this->Add(ret);
}

void MediaPlayerFFMepeg::Add(const QString& message)
{
	if (message.isEmpty()) this->ui.plainTextEdit->appendPlainText("Try write empty message");
	this->ui.plainTextEdit->appendPlainText(message);
}

void MediaPlayerFFMepeg::on_btn_getAVFormat_clicked()
{
	QString ret = this->info->getAVFormatInfo();
	this->Add(ret);
}
