#ifndef ANOTHERWINDOW1_H
#define ANOTHERWINDOW1_H
#include <QWidget>

namespace Ui {
class AnotherWindow1;
}

class AnotherWindow1 : public QWidget
{
    Q_OBJECT

public:
    explicit AnotherWindow1(QWidget *parent = 0);
    ~AnotherWindow1();

signals:
    void firstWindow();  // Сигнал для первого окна на открытие

private slots:
    // Слот-обработчик нажатия кнопки
    void on_pushButton_clicked();

private:
    Ui::AnotherWindow1 *ui;
};

#endif // ANOTHERWINDOW_H
