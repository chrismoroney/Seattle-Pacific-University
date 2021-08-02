#include "connect4app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connect4App w;
    w.show();
    return a.exec();
}
