#include "multifunctionaldashboard.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    multiFunctionalDashBoard w;
    w.show();
    return a.exec();
}
