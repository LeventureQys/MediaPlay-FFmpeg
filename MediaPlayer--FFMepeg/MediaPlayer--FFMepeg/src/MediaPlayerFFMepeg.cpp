#include "../include/MediaPlayerFFMepeg.h"
#pragma execution_character_set("utf-8") 

MediaPlayerFFMepeg::MediaPlayerFFMepeg(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->info = new BaseInfos(this);
	this->core = new MediaPlay_Core();
	this->core->register_func([=](const uchar* data, const int width, const int height) {
		this->FrameRender(data, width, height);
		});
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

void MediaPlayerFFMepeg::on_btn_chooseMeadia_clicked()
{
	QString path = QFileDialog::getOpenFileName(this, "选择视频文件", "D:\\Test\\Video\\", "MP4视频(*.mp4);;AVI视频(*.avi);;WMV视频(*.wmv)");
	if (path.isEmpty()) {
		this->Add("请选择视频文件");
		return;
	}
	this->current_file = path;
	this->core->playVideo(this->current_file.toUtf8());
	this->core->VideoPlayControl(true);
}

void MediaPlayerFFMepeg::on_btn_VideoClose_clicked()
{
	this->core->VideoPlayEnd();
}

void MediaPlayerFFMepeg::on_btn_play_clicked(bool Checked)
{
		if (Checked) {
			this->ui.btn_play->setText("播放");
			this->core->VideoPlayControl(true);
		}
		else {
			this->ui.btn_play->setText("暂停");
			this->core->VideoPlayControl(false);
		}
}

void MediaPlayerFFMepeg::FrameRender(const uchar* data, const int width, const int height)
{
	QImage img(data, width, height, QImage::Format_RGB32);
	this->ui.lab_mediaPlayer->setPixmap(QPixmap::fromImage(img));
	this->core->delay(this->delay);
}

void MediaPlayerFFMepeg::on_btn_getAVFormat_clicked()
{
	QString ret = this->info->getAVFormatInfo();
	this->Add(ret);
}
