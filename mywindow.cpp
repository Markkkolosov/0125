#include "mywindow.h"

mywindow::mywindow(QWidget *parent) : QWidget(parent) {
    this->setGeometry(100,100, 300,500);

    lsd = new QLCDNumber(this);
    lsd->setGeometry(100,30,100,40);

    btnStart = new QPushButton(this);
    btnStart->setGeometry(100,100,100,30);
    btnStart->setText("Старт");

    btnSbr = new QPushButton(this);
    btnSbr->setGeometry(100,150,100,30);
    btnSbr->setText("Сброс");

    stroka = new QLineEdit(this);
    stroka->setGeometry(100,0,100,30);

    btnUp = new QRadioButton(this);
    btnUp->setGeometry(10,200, 200,30);
    btnUp->setText("Прямой");
    btnUp->setChecked(true);

    btnDown = new QRadioButton(this);
    btnDown->setGeometry(200,200, 200,30);
    btnDown->setText("Обратный");

    timer = new QTimer(this);
    timer->setInterval(500);

    second = 0;

    connect(timer, SIGNAL(timeout()),this, SLOT(time()));
    connect(btnStart, SIGNAL(pressed()),this, SLOT(start()));
    connect(btnSbr, SIGNAL(pressed()),this, SLOT(clear()));
    connect(stroka, SIGNAL(textEdited(QString)),this, SLOT(change(QString)));

 }
void mywindow::clear() {
    timer->stop();
    second = this->stroka->text().toInt();
    lsd->display(second);
    btnStart->setText("Старт");

}

void mywindow::time() {
    if (btnDown->isChecked()){
        second--;
        lsd->display(second);
    } else {
        second++;
        lsd->display(second);
    }

}

void mywindow::start() {
    if (timer->isActive()) {
        timer->stop();
        btnStart->setText("Старт");
    }
    else {
        timer->start();
        btnStart->setText("Стоп");
    }
}

void mywindow::change(QString newText) {
    timer->stop();
    btnStart->setText("Старт");
    second = newText.toInt();
    lsd->display(second);
}

