#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "error.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

    //connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(on_pushButton_clear_clicked()));
    //connect(ui->pushButton_delete, SIGNAL(clicked()), this, SLOT(on_pushButton_delete_clicked()));
    //connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(on_pushButton_dot_clicked()));
    //connect(ui->pushButton_equally, SIGNAL(clicted()), this, SLOT(on_pushButton_equally_clicked()));


    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_dvide, SIGNAL(clicked()), this, SLOT(math_operations()));


    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_dvide->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    if(ui->result_show->text().size() > 8)
    {
        printError("Is too long!");
        return;
    }

    QPushButton *button = (QPushButton *) sender();
    QString add = "";
    if(ui->result_show->text().contains('.') && !ui->result_show->text().contains('e'))
    {
        if (button->text() == "0")
        {
           if(ui->result_show->text().back() == '.')
           {
                add.append(".");
           }
           add.append("0");
           if(ui->result_show->text().back() == '0')
           {
               int i = 1;
               for(; ui->result_show->text().at(ui->result_show->text().size() - i) == '0';  i++)
               {
                  add.append("0");
               }
               if(ui->result_show->text().at(ui->result_show->text().size() - i) == '.')
               {
                  //add = add.rightJustified(ui->result_show->text().size() - 1, '.');
                  QString res = ".";
                  res.append(add);
                  add = res;
               }
           }
        }
    }
    double all_numbers = (ui->result_show->text() + button->text()).toDouble();
    QString new_label = QString::number(all_numbers, 'g', 9);
    new_label.append(add);
    ui->result_show->setText(new_label);
}

void MainWindow::math_operations()
{
    if(isPush)
    {
        if (ui->pushButton_plus->isChecked())
        {
            ui->pushButton_plus->setChecked(false);
        }
        else if (ui->pushButton_minus->isChecked())
        {
            ui->pushButton_plus->setChecked(false);
        }
        else if (ui->pushButton_multiply->isChecked())
        {
            ui->pushButton_plus->setChecked(false);
        }
        else if (ui->pushButton_dvide->isChecked())
        {
            ui->pushButton_plus->setChecked(false);
        }
        QPushButton *button = (QPushButton *) sender();
        button->setChecked(true);
    }
    else
    {
        num_first = ui->result_show->text().toDouble();
        ui->result_show->setText("0");

        QPushButton *button = (QPushButton *) sender();
        button->setChecked(true);
        isPush = 1;
    }
}

void MainWindow::on_pushButton_equally_clicked()
{
    double num_second = ui->result_show->text().toDouble();

    if (ui->pushButton_plus->isChecked())
    {
        num_first += num_second;
        ui->pushButton_plus->setChecked(false);
    }
    else if (ui->pushButton_minus->isChecked())
    {
        num_first -= num_second;
        ui->pushButton_minus->setChecked(false);
    }
    else if (ui->pushButton_multiply->isChecked())
    {
        num_first *= num_second;
        ui->pushButton_multiply->setChecked(false);
    }
    else if (ui->pushButton_dvide->isChecked())
    {
        if(num_second == 0)
        {
            printError("Division by 0!");
        }
        else
        {
            num_first /= num_second;
        }
        ui->pushButton_dvide->setChecked(false);
    }

    QString new_label = QString::number(num_first, 'f', 0);
    ui->result_show->setText(new_label);
    isPush = 0;
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->result_show->text().contains('.')))
    {
        ui->result_show->setText(ui->result_show->text() + ".");
    }
    else
    {
        printError("Double point!");
    }
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->result_show->setText("0");
}

void MainWindow::on_pushButton_delete_clicked()
{
    //double all_numbers = ui->result_show->text().toDouble();
    //QString new_label = QString::number(all_numbers, 'f', 0);
    //new_label.chop(1);
    //all_numbers = new_label.toDouble();
    //new_label = QString::number(all_numbers, 'g', 9);
    //ui->result_show->setText(new_label);

    QString new_label = ui->result_show->text();
    new_label.chop(1);
    if(new_label.size() == 0)
    {
        new_label = "0";
    }
    else if(new_label.size() == 1)
    {
        if(new_label.at(0) == '-')
        {
           new_label = "0";
        }
    }
    else if(new_label.size() == 2)
    {
        if(new_label.at(0) == '0' && new_label.at(1) == '0')
        {
           new_label = "0";
        }
    }
    ui->result_show->setText(new_label);
}


void MainWindow::on_pushButton_pm_clicked()
{
   if(ui->result_show->text().at(0) == '-')
   {
      ui->result_show->setText(ui->result_show->text().right(ui->result_show->text().size() - 1));
   }
   else
   {
      if(ui->result_show->text().at(0) == '0' && ui->result_show->text().size() == 1)
      {
        printError("Minus Zero!");
      }
      else
      {
          QString res = "-";
          res.append(ui->result_show->text());
          ui->result_show->setText(res);
      }
   }
}


void MainWindow::printError(QString str)
{
    error = new Error(this);
    error->setModal(true);
    error->setError(str);
    error->show();
}

void MainWindow::on_pushButton_help_clicked()
{
    //hide(); скрыть основное окно
    if(help != nullptr)
    {
        //printf("%d", (help == nullptr));
        if(!help->isVisible())
        {
            help = new Help(this);
            help->show();
        }
    }
    else
    {
        help = new Help(this);
        help->show();
    }
}

