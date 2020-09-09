#include "clientbrashaptique.h"
#include "cclientudp.h"

#include <QtMath>

ClientBrasHaptique::ClientBrasHaptique()
{
    bras=new CBrasHaptique;
    bras->show();

    database=new cbdd("192.168.1.76",8086,"db");

    client.HelloUDP();

    QObject::connect(bras,&CBrasHaptique::posGripChanged,this,&ClientBrasHaptique::Angle_roll);
    QObject::connect(bras,&CBrasHaptique::posGripChanged,this,&ClientBrasHaptique::Angle_pitch);
}
ClientBrasHaptique::~ClientBrasHaptique()
{

}

void ClientBrasHaptique::Angle_roll(QPoint p_posGrip)
{
    qreal posx = p_posGrip.x();
    float angle;

    angle = qAtan2(posx,joystick);

    //database->savebdd(angle, "Angle roll");

    char IEEE[4];

    memcpy(IEEE, &angle, 4);

    QByteArray Data_roll("DREF\x0\x00\x00\x00\x00sim/joystick/yoke_roll_ratio",38);

    int i;
    for(i=0;i<4;i++)
    {
        Data_roll[5+i]=IEEE[i];
    }

    for(i=0;i<509-38;i++)
    {
        Data_roll.append(0x20);
    }

    client.sendData(Data_roll);
}

void ClientBrasHaptique::Angle_pitch(QPoint p_posGrip)
{
    qreal posy = p_posGrip.y();
    float angle;

    angle = qAtan2(posy,joystick);
    
    //database->savebdd(angle, "Angle pitch");
    
    char IEEE[4];

    memcpy(IEEE, &angle, 4);

    QByteArray Data_pitch("DREF\x0\x00\x00\x00\x00sim/joystick/yoke_pitch_ratio",39);

    int i;
    for(i=0;i<4;i++)
    {
        Data_pitch[5+i]=IEEE[i];
    }

    for(i=0;i<509-39;i++)
    {
        Data_pitch.append(0x20);
    }

    client.sendData(Data_pitch);
}
