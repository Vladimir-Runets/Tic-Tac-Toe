#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "anotherwindow1.h"
#include "widget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    // Слоты от кнопок главного окна
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    // второе и третье окна
    AnotherWindow1 *secondWindow;
    AnotherWindow1 *thirdWindow;
    Widget widget;
};

#endif // MAINWINDOW_H
