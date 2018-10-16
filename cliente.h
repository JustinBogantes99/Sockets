#ifndef CLIENTE_H
#define CLIENTE_H


#include <QObject>
#include <QtDebug>
#include <QtNetwork/QTcpSocket>

class Cliente : public QObject
{
    Q_OBJECT
public:
    explicit Cliente(QObject *parent = 0);

    void Connect();

signals:

public slots:

private:
    QTcpSocket *socket;
};


#endif // CLIENTE_H
