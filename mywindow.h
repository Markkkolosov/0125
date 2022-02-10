#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QTimer>
#include <QLineEdit>
#include <QRadioButton>

class mywindow : public QWidget {
    Q_OBJECT
private:
    QLCDNumber *lsd;
    QPushButton *btnStart;
    QPushButton *btnSbr;
    QTimer *timer;
    QLineEdit *stroka;
    QRadioButton *btnUp;
    QRadioButton *btnDown;
    int second;
public:
    explicit  mywindow(QWidget *parent = nullptr);
public slots:
    void time();
    void start();
    void clear();
    void change(QString);
};

#endif // MYWINDOW_H
