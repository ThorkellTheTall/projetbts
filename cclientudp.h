#ifndef CCLIENTUDP_H
#define CCLIENTUDP_H

#include <QObject>
#include <QUdpSocket>
#include <string>
#include <iostream>

class CClientUDP : public QObject
{
    Q_OBJECT
public:
    explicit CClientUDP(QObject *parent = 0);
    void HelloUDP();
    void sockDisconnect();
    void sendData(QByteArray Data);

public slots:
    void readyRead();


private:
    QUdpSocket *socket;
};

#endif // CCLIENTUDP_H
