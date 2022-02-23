#include "error.h"
#include "ui_error.h"

Error::Error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Error)
{
    ui->setupUi(this);
}

void Error::setError(QString str)
{
    ui->label->setText("Error: " + str);
}

Error::~Error()
{
    delete ui;
}
