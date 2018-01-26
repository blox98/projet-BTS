#include "cihmlampadaire.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CIhmLampadaire w;
    w.show();

    return a.exec();
}
