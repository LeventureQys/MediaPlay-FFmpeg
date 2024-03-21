#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MediaPlayerFFMepeg.h"

class MediaPlayerFFMepeg : public QMainWindow
{
    Q_OBJECT

public:
    MediaPlayerFFMepeg(QWidget *parent = nullptr);
    ~MediaPlayerFFMepeg();

private:
    Ui::MediaPlayerFFMepegClass ui;
};
