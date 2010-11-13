#include <QtGui/QApplication>
#include <pokedexwindow.h>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pokedexWindow *window = new pokedexWindow;

    window->run();
    return a.exec();
}
