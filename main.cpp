#include <QCoreApplication>
#include "BlandxTraverse.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BlandxTraverse traverse;

    //if (argc < 2)
    //    cout << "No Directory Parameter..." << endl;
    //else
    traverse.compile("c:\\TEST");

    system("PAUSE");
    return a.exit();
}
