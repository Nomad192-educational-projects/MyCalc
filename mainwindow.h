#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "error.h"
#include "help.h"

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
    Error *error;
    Help *help = nullptr;
    double num_first;
    int isPush = 0;

private slots:
    void digits_numbers();
    void math_operations();

    void on_pushButton_dot_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_equally_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_pm_clicked();

    void printError(QString str);
    void on_pushButton_help_clicked();
};

#endif // MAINWINDOW_H
