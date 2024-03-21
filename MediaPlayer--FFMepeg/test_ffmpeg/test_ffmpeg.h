#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test_ffmpeg.h"

class test_ffmpeg : public QMainWindow
{
    Q_OBJECT

public:
    test_ffmpeg(QWidget *parent = nullptr);
    ~test_ffmpeg();

private:
    Ui::test_ffmpegClass ui;
};
