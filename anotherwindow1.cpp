#include "anotherwindow1.h"
#include "ui_anotherwindow1.h"

AnotherWindow1::AnotherWindow1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnotherWindow1)
{
    ui->setupUi(this);
}

AnotherWindow1::~AnotherWindow1()
{
    delete ui;
}

void AnotherWindow1::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
}
