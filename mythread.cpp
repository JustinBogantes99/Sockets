#include "MyThread.h"

MyThread::MyThread(int ID ,QObject *parent):
    QThread (parent)
{
    this->socketDescriptor = ID;
}

void MyThread::run()
{
    //qDebug << "Start thread";
    socket = new QTcpSocket();
    if (!socket->setSocketDescriptor(this->socketDescriptor)){
        emit error(socket->error());
        return;
    }
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    exec();
}

void MyThread::readyRead()
{
    QByteArray Data = socket->readAll();
    socket->write(Data);
}

void MyThread::disconnected()
{
    socket->deleteLater();
    exit(0);
}
