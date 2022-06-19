#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnOK, &QPushButton::clicked, this, &MainWindow::savefile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::savefile()
{
    qDebug() << "enter slot";
    QFile file("/Users/azhun/test.json");
    if (file.open(QFile::WriteOnly | QIODevice::Truncate)){
        qDebug() << "ok";
        QTextStream out(&file);
        lineEditProject = ui->lineEditProject;
//        lineEditAdb = ui->lineEditAdb;
        lineEditHwVersion = ui->lineEditHwVersion;
//        lineEditVariant = ui->lineEditVariant;

        out << lineEditProject->text() << Qt::endl;
//        out << lineEditAdb->text() << Qt::endl;
        out << lineEditHwVersion->text() << Qt::endl;
//        out << lineEditVariant->text() << Qt::endl;

    }
    else
        qDebug() << "nok";
    return true;
}
