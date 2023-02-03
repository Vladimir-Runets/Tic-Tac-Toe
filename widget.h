#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QMessageBox>
#include <iostream>
#include "MyButton.h"
#include <vector>

class Widget : public QWidget {
Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr, int _size = 3,bool state = true);

    ~Widget() override;

    int whoWin();

private slots:

    void onClickedButton();
    void onClickedButton2();

private:
    int size;
    bool state;
    std::vector<std::vector<MyButton*>> buttons;
};

#endif
