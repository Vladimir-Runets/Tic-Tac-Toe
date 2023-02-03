#include "mainwindow.h"
#include "ui_mainwindow.h"

bool state;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Инициализируем второе окно
    secondWindow = new AnotherWindow1();
    // подключаем к слоту запуска главного окна по кнопке во втором окне
    connect(secondWindow, &AnotherWindow1::firstWindow, this, &MainWindow::show);
    // Инициализируем третье окно
    thirdWindow = new AnotherWindow1();
    // подключаем к слоту запуска главного окна по кнопке в третьем окне
    connect(thirdWindow, &AnotherWindow1::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Widget* TTT = new Widget(nullptr, 3,state);
    TTT->show();
    //widget.show();  // Показываем второе окно
    this->close();    // Закрываем основное окно
}

void MainWindow::on_pushButton_2_clicked()
{
    Widget* TTT = new Widget(nullptr, 4,state);
    TTT->show();
    //widget.show();  // Показываем третье окно
    this->close();    // Закрываем основное окно
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Сложный"){
        state = true;
    }else {
        state = false;
}
}
