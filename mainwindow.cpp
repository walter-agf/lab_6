#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    h_limit = 1000;
    v_limit = 800;
    dt = 10;

    timer = new QTimer(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,h_limit,v_limit);
    scene->setBackgroundBrush(QPixmap(":/image/stars.jpg"));

    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();

    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));


//    bars.append(new cuerpograf(0,-7000,2,0,70,120));
//    bars.append(new cuerpograf(0,0,0,0,70000,300));
//    bars.append(new cuerpograf(4000,5000,-1.6,1.2,25,100));

//    bars.append(new cuerpograf(0,0,0,0,50000,200));
//    bars.append(new cuerpograf(-5000,0,0,-2,70,70));
//    bars.append(new cuerpograf(5000,0,0,2,25,100));
//    bars.append(new cuerpograf(0,-5000,2,0,70,70));
//    bars.append(new cuerpograf(0,5000,-2,0,70,70));

//    for (int i=0;i<bars.size() ;i++ ) {
//        bars.at(i)->actualizar(dt);
//        scene->addItem(bars.at(i));
//    }


}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete scene;
}

void MainWindow::actualizar()
{
    for (int i=0;i<bars.size() ;i++ ) {
        for (int j=0;j<bars.size() ;j++ ) {
            if(i!=j){
                bars.at(i)->getEsf()->acelerar(bars.at(j)->getEsf()->getPX(),bars.at(j)->getEsf()->getPY(),bars.at(j)->getEsf()->getMasa());
                //bars.at(i)->actualizar(dt);

            }
        }
        bars.at(i)->actualizar(dt);
        bars.at(i)->actualizar(dt);
        datos += to_string(bars.at(i)->getEsf()->getPX());
        datos.push_back('\t');
        datos += to_string(bars.at(i)->getEsf()->getPY());
        datos.push_back('\t');
    }
    datos.push_back('\n');
}


void MainWindow::on_pushButton_clicked()
{
    string name ="../lab_6/doc/Space.txt";
    fstream doc (name.c_str(), fstream :: out);

    timer->start(dt);
    qDebug() << entrada;
}

void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
    bars.back()->guardar_datos(datos, nombre);
}

void MainWindow::on_pushButton_3_clicked()
{
    float uno, dos, tres, cuatro, cinco, seis;
    uno = ui->n1->value();
    dos = ui->n2->value();
    tres = ui->n3->value();
    cuatro = ui->n4->value();
    cinco = ui->n5->value();
    seis = ui->n6->value();

    //nombre += "\t" + ui->text->;



    bars.append(new cuerpograf(uno,dos,tres,cuatro,cinco,seis));

    bars.back()->actualizar(dt);
    scene->addItem(bars.back());

}
