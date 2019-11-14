#include "fotbaldb.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FotbalDB w;
    w.show();
    return a.exec();
}
