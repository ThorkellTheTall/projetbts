#ifndef CLIENTBRASHAPTIQUE_H
#define CLIENTBRASHAPTIQUE_H
#include<QWidget>
#include "cbrashaptique.h"
#include "cclientudp.h"
#include "cbdd.h"
#include <QDebug>
#include <QPoint>

class cbdd;

class ClientBrasHaptique : public QWidget
{

    private:
        //Un bras haptique est contenu
        CBrasHaptique *bras;
        //Pour stocker la position du grip
        QPoint posGrip;
        int joystick = 600;
    public:
        ClientBrasHaptique();
        ~ClientBrasHaptique();
        //client UDP
        CClientUDP client;
        //influxdb
        cbdd *database;
        //fonction d'envoi données
        void Angle_roll(QPoint p_posGrip);
        void Angle_pitch(QPoint p_posGrip);
    public slots:
        void printPosGrip(QPoint p_posGrip);

};

#endif // CLIENTBRASHAPTIQUE_H
