#include "rollcallsystem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RollCallSystem w;
    w.show();

    return a.exec();
}
