#include"ProjectGUI.h"
#include <QtWidgets/QApplication>
#include "SongController.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SongRepo rep;
    SongController sc{ rep };
    ProjectGui w{ sc };
    w.show();
    return a.exec();
}
