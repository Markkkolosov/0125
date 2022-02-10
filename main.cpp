#include <QApplication>
#include <mywindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mywindow *x = new mywindow();
    x->show();

    return a.exec();
}
