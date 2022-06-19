#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QHBoxLayout>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QLineEdit *lineEditProject;
    QLineEdit *lineEditAdb;
    QLineEdit *lineEditHwVersion;
    QLineEdit *lineEditVariant;

private slots:
    bool savefile();
};
#endif // MAINWINDOW_H
