#ifndef __CONFIGURACION_H__
#define __CONFIGURACON_H__

struct Configuracion{
    int ValorMaximoXEquipo;
    int ARQ;
    int DEF;
    int MED;
    int DEL;
};

/*
    Pre: El TDA no debe haber sido creado
    Pos: Se crea el TDA con los siguientes valores:
    ValorMaximoXEquipo=100.000.000, ARQ=3, DEF=5, MED=5, DEL=4.
*/
void crear(Configuracion &configuracion);

/*----------------------------------------------------------------------------*/
/*
    Pre: Configuracion debe haber sido creado
    Pos: Se extraen los valores  del archivo configuracion.conf
         y se los asigna a la instancia creada
*/
void setConfiguracion(Configuracion &configuracion);

/*----------------------------------------------------------------------------*/
/*
    Pre: Configuracion debe haber sido creado
    Pos: Se obtiene el valor maximo q puede valer un equipo.
*/
int getValorMaximoXEquipo(Configuracion &configuracion);

/*----------------------------------------------------------------------------*/
/*
    Pre: Configuracion debe haber sido creado
    Pos: Se obtiene el numero maximo de arqueros q puede tener el equipo.
*/
int getARQ(Configuracion &configuracion);

/*----------------------------------------------------------------------------*/
/*
    Pre: Configuracion debe haber sido creado
    Pos: Se obtiene el numero maximo de defendores q puede tener el equipo.
*/
int getDEF(Configuracion &configuracion);

/*----------------------------------------------------------------------------*/
/*
    Pre: Configuracion debe haber sido creado
    Pos: Se obtiene el numero maximo de mediocampistas q puede tener el equipo.
*/
int getMED(Configuracion &configuracion);

/*----------------------------------------------------------------------------*/
/*
    Pre: Configuracion debe haber sido creado
    Pos: Se obtiene el numero maximo de delanteros q puede tener el equipo.
*/
int getDEL(Configuracion &configuracion);

/*----------------------------------------------------------------------------*/
#endif // __CONFIGURACION_H__

