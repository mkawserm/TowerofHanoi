#include "towerofhanoiview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TowerofHanoiView w;
    w.show();

    return a.exec();
}
