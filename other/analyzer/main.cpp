#include "analyzer.h"
#include <QApplication>
#include <string>

using std::string;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Analyzer w;

    w.show();

    return a.exec();
}
