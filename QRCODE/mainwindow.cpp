#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

 timer = new QTimer(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::guncelle()
{
    cap >> frame;
    cvtColor(frame, frame, CV_BGR2RGB);

    yuz.load("C:/OpencvQTt/opencv-3.4.3/source/data/haarcascades/haarcascade_frontalface_default.xml");
    yuz.detectMultiScale(frame, yuz_tanima, 1.1, 2,  0|CV_HAAR_SCALE_IMAGE,cv::Size(frame.cols/4, frame.rows/4));

    for( size_t i = 0; i < yuz_tanima.size(); i++)
    {
        cap.retrieve(frame);
        cv::rectangle(frame, yuz_tanima[i], cv::Scalar( 12, 50, 245 ),3);

    }
    qt_image = QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(qt_image));
    ui->label->resize(ui->label->pixmap()->size());
}

void MainWindow::on_kapa_clicked()
{
    disconnect(timer,SIGNAL(timeout()),this,SLOT(guncelle()));
    cap.release();

yansitma(image);

     cout<<"Kamera Kapandı."<<endl;
}


void MainWindow::on_ac_clicked()
{
    cap.open(0);
    if(!cap.isOpened())
    {
     cout<<"Kamera Acilmadi!"<<endl;
    }
    else
    {
     cout<<"Kamera Acildi."<<endl;

     connect(timer,SIGNAL(timeout()),this,SLOT(guncelle()));
     timer->start(20);
    }
}

