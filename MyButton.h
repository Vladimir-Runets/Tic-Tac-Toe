#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton {
public:
    MyButton();

    int getValue() const { return value; }

    void setValue(int v) { value = v; }

    bool canChanged() const { return can_changed; }

    void setCanChanged(bool can) { can_changed = can; }

protected:
    void paintEvent(QPaintEvent *) override;

private:
    int value;
    bool can_changed;
};

#endif
