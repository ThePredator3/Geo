#include "Headers/MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication qApplication(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    mainWindow.slotReadyRead();
    return qApplication.exec();
}
