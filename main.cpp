#include <QCoreApplication>
#include "cliente.cpp"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Cliente cTest;
    cTest.Connect();

    return a.exec();
}
