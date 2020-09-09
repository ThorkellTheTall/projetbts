#include "cbdd.h"
#include "clientbrashaptique.h"
#include <winsock2.h>


cbdd::cbdd(string AdresseIP,int port,string database):si(AdresseIP,port,database)
{
    WSADATA WSAData;
    WSAStartup(MAKEWORD(2,0), &WSAData);
    table1 = "simuVol";
}

void cbdd::savebdd(float Angle, string nom)
{

    influxdb_cpp::builder()
        .meas(table1)
        .field(nom,Angle)
        .post_http(si,&resp);

    cout << resp << endl;

}
