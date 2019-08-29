#include "mainwindow.h"
#include <QApplication>
#include "areena.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */




int main(int argc, char *argv[])
{
    srand (time(0));
    QApplication a(argc, argv);


    //levelup w;
    MainWindow w;
    w.show();

    return a.exec();
}

