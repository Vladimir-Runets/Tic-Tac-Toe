#include "widget.h"

Widget::Widget(QWidget *parent, int _size,bool _state): QWidget(parent) , size(_size),state{_state}{
    QGridLayout *layout = new QGridLayout(this);
//    for (int i = 0; i < size * size; ++i) {
//        buttons[i] = new MyButton();
//        buttons[i]->setMaximumSize(600, 600);
//        buttons[i]->setMinimumSize(50, 50);
//        layout->addWidget(buttons[i], i / size, i % size);
//        connect(buttons[i], SIGNAL(clicked()), SLOT(onClickedButton()));
//    }
    buttons.resize(size);

    for(int i = 0; i < size; i++){
        buttons[i].resize(size);
        for(int j = 0; j < size; j++){
            buttons[i][j] = new MyButton();
            buttons[i][j]->setMaximumSize(600, 600);
            buttons[i][j]->setMinimumSize(50, 50);
            layout->addWidget(buttons[i][j], i, j);
            if (state == false){
            connect(buttons[i][j], SIGNAL(clicked()), SLOT(onClickedButton()));
            }
            else {
            connect(buttons[i][j], SIGNAL(clicked()), SLOT(onClickedButton2()));
            }
        }
    }
    setStyleSheet("background-color: #0F927D;");
    layout->setHorizontalSpacing(20);
    layout->setVerticalSpacing(20);
    setLayout(layout);
}

Widget::~Widget() = default;

void Widget::onClickedButton() {
    MyButton *source = dynamic_cast<MyButton *>(this->sender());

    if (source->getValue() == -1) {
        source->setValue(1);
        source->setCanChanged(false);
        int who_win = whoWin();
        if (who_win != -1) {
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("You win!!!");
            msgBox.setText("Not bad!");
            msgBox.exec();
            for(int i = 0; i < size; i++){
                for (MyButton *t: buttons[i]) {
                    t->setCanChanged(true);
                    t->setValue(-1);
                }
            }
            repaint();
            return;
        }

        int cant_count = 0;
        for(int i = 0; i < size; i++){
            for (MyButton *t: buttons[i]) {
                if (!t->canChanged()) {
                    cant_count++;
                }
            }
        }
        if (cant_count == size * size) {
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("Draw!!!");
            msgBox.setText("Try again!");
            msgBox.exec();
            for(int i = 0; i < size; i++){
                for (MyButton *t: buttons[i]) {
                    t->setCanChanged(true);
                    t->setValue(-1);
                }
            }
            repaint();
            return;
        }

        int i;
        int j = 0;
        do {
            i = rand() % (size * size);
            j = i % size;
            i = i / size;

        }while (!buttons[i][j]->canChanged());
        buttons[i][j]->setValue(0);
        buttons[i][j]->setCanChanged(false);

        who_win = whoWin();
        if (who_win != -1) {
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("Computer win!!!");
            msgBox.setText("You're loser!");
            msgBox.exec();
            for(int i = 0; i < size; i++){
                for (MyButton *t: buttons[i]) {
                    t->setCanChanged(true);
                    t->setValue(-1);
                }
            }
            repaint();
            return;
        }

        repaint();
    }

}


void Widget::onClickedButton2() {
    MyButton *source = dynamic_cast<MyButton *>(this->sender());

    if (source->getValue() == -1) {
        source->setValue(1);
        source->setCanChanged(false);
        int who_win = whoWin();
        if (who_win != -1) {
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("You win!!!");
            msgBox.setText("Not bad!");
            msgBox.exec();
            for(int i = 0; i < size; i++){
                for (MyButton *t: buttons[i]) {
                    t->setCanChanged(true);
                    t->setValue(-1);
                }
            }
            repaint();
            return;
        }

        int cant_count = 0;
        for(int i = 0; i < size; i++){
            for (MyButton *t: buttons[i]) {
                if (!t->canChanged()) {
                    cant_count++;
                }
            }
        }
        if (cant_count == size * size) {
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("Draw!!!");
            msgBox.setText("Try again!");
            msgBox.exec();
            for(int i = 0; i < size; i++){
                for (MyButton *t: buttons[i]) {
                    t->setCanChanged(true);
                    t->setValue(-1);
                }
            }
            repaint();
            return;
        }

        int i;
        int j;
                do {
                    if(size % 2 != 0) {
                                if(buttons[(size-1)/2][(size-1)/2]->getValue() == -1)
                                {
                                    i = 1;
                                    j = 1;
                                }
                            }
                            if(buttons[0][0]->getValue() == -1){
                                i = 0;
                                j = 0;
                            }
                            else if(buttons[size-1][size-1]->getValue() == -1){
                                i = size-1;
                                j = size-1;
                            }
                            else if(buttons[0][size-1]->getValue() == -1){
                                i = 0;
                                j = size - 1;
                            } else if(buttons[size - 1][0]->getValue() == -1){
                                i = size - 1;
                                j = 0;
                            }
                            else {
                                i = rand() % (size * size);
                                j = i % size;
                                i = i / size;
                            }
                }while (!buttons[i][j]->canChanged());
                buttons[i][j]->setValue(0);
                buttons[i][j]->setCanChanged(false);

        who_win = whoWin();
        if (who_win != -1) {
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("Computer win!!!");
            msgBox.setText("You're loser!");
            msgBox.exec();
            for(int i = 0; i < size; i++){
                for (MyButton *t: buttons[i]) {
                    t->setCanChanged(true);
                    t->setValue(-1);
                }
            }
            repaint();
            return;
        }

        repaint();
    }
}



int Widget::whoWin() {
    for(int i = 0; i < size - 2; i++){
           for(int j = 0; j < size - 2; j++){
               if(
                       buttons[i][j]->getValue() != -1 && buttons[i + 1][j + 1]->getValue() != -1 && buttons[i + 2][j + 2]->getValue() != -1 &&
                       buttons[i][j]->getValue() == buttons[i + 1][j + 1]->getValue()  && buttons[i + 1][j + 1]->getValue() == buttons[i + 2][j + 2]->getValue()
                       ){
                   if(buttons[i][j]->getValue() == 1){
                       return 1;
                   }else if (buttons[i][j]->getValue() == 0){
                       return 0;
                   }
               }
           }
       }
       for(int i = 0; i < size - 2; i++){
           for(int j = size - 1; j >= 2; j--){
               if(buttons[i][j]->getValue() != -1 && buttons[i + 1][j - 1]->getValue() != -1 && buttons[i + 2][j - 2]->getValue() != -1 &&
            buttons[i][j]->getValue() == buttons[i + 1][j - 1]->getValue() && buttons[i + 1][j - 1]->getValue() == buttons[i + 2][j - 2]->getValue()){
                   if(buttons[i][j]->getValue() == 1){
                       return 1;
                   }else if (buttons[i][j]->getValue() == 0){
                       return 0;
                   }
               }
           }
       }
       for(int i = 0; i < size; i++){
           for(int j = 0; j < size - 2; j++){
               if(buttons[i][j]->getValue() != -1 && buttons[i][j + 1]->getValue() != -1 && buttons[i][j + 2]->getValue() != -1 &&
                  buttons[i][j]->getValue() == buttons[i][j + 1]->getValue() && buttons[i][j + 1]->getValue() == buttons[i][j + 2]->getValue()){
                   if(buttons[i][j]->getValue() == 1){
                       return 1;
                   }else if (buttons[i][j]->getValue() == 0){
                       return 0;
                   }
               }
           }
       }
       for(int i = 0; i < size - 2; i++){
           for(int j = 0; j < size; j++){
               if(buttons[i][j]->getValue() != -1 && buttons[i + 1][j]->getValue() != -1 && buttons[i + 2][j]->getValue() != -1 &&
                  buttons[i][j]->getValue() == buttons[i + 1][j]->getValue() && buttons[i + 1][j]->getValue() == buttons[i + 2][j]->getValue()){
                   if(buttons[i][j]->getValue() == 1){
                       return 1;
                   }else if (buttons[i][j]->getValue() == 0){
                       return 0;
                   }
               }
           }
       }

       return -1;
}
