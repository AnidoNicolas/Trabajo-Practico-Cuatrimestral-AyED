#include "configuracion.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void crear(Configuracion &configuracion){
    configuracion.ValorMaximoXEquipo=100000000;
    configuracion.ARQ=3;
    configuracion.DEF=5;
    configuracion.MED=5;
    configuracion.DEL=4;
}

void setConfiguracion(Configuracion &configuracion){
    char campo[20],valor[10];
    int i=1;
    ifstream fconfiguracion("configuracion.conf", ios::in);
    if(!fconfiguracion) cout << "el archivo no existe";
    while(!fconfiguracion.eof() ){
        fconfiguracion.getline(campo,21,'=');
        fconfiguracion.getline(valor,10,'\n');
        if(i==1) configuracion.ValorMaximoXEquipo=atoi(valor);
        if(i==2) configuracion.ARQ=atoi(valor);
        if(i==3) configuracion.DEF=atoi(valor);
        if(i==4) configuracion.MED=atoi(valor);
        if(i==5) configuracion.DEL=atoi(valor);
        i++;
    }
    fconfiguracion.close();
}

int getValorMaximoXEquipo(Configuracion &configuracion){
    return configuracion.ValorMaximoXEquipo;
}

int getARQ(Configuracion &configuracion){
    return configuracion.ARQ;
}

int getDEF(Configuracion &configuracion){
    return configuracion.DEF;
}

int getMED(Configuracion &configuracion){
    return configuracion.MED;
}

int getDEL(Configuracion &configuracion){
    return configuracion.DEL;
}
