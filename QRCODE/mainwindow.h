#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>


#include <QImage>
#include <vector>
#include <iostream>
#include <QTimer>

using namespace cv;
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void guncelle();
   // void yansitma();

    void on_kapa_clicked();

    void on_ac_clicked();

private:
    Ui::MainWindow *ui;


    QTimer *timer;   //Zaman
    VideoCapture cap; //Kamera
    Mat image;
    Mat frame;  //Kamera dan gelen Görüntünün Atanacağı matris
    QImage qt_image;  //pixmap ile göstermek için
    std::vector<cv::Rect> yuz_tanima;  //Tanımlamayı kare içine almak için
    CascadeClassifier yuz; //.xml Dosyası için


     void show_frame(Mat &);
};
#endif // MAINWINDOW_H
