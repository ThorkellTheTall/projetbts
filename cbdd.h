#ifndef CBDD_H
#define CBDD_H
#include <stdio.h>
#include <iostream>
#include "influxdb.hpp"
#include "clientbrashaptique.h"

using namespace std;


class cbdd
{
private:
    string table1;
    string AdresseIP;
    string database;
    int port;
    string requete;
    string resp;
    influxdb_cpp::server_info si;
public:
    cbdd(string AdresseIP,int port,string database);
    void savebdd(float Angle, string nom);
};

#endif // CBDD_H
