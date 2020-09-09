#include <QApplication>
#include "cclientudp.h"
#include "clientbrashaptique.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ClientBrasHaptique *bras=new ClientBrasHaptique;

    return a.exec();
}
