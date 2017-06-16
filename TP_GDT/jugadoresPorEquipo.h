#ifndef JUGADORESPOREQUIPO_H_INCLUDED
#define JUGADORESPOREQUIPO_H_INCLUDED

struct JugadoresPorEquipo{
    int idEquipo;
    int idJugador;
};

//PRIMITIVAS
/*
    Pre: El TDA no debe haber sido creado con anteridad.
    Post: Crea el TDA con los siguientes valores:
         idEquipo=0; idJugador=0;
*/
void crear(JugadoresPorEquipo &jugadoresPorEquipo);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el idEquipo de jugadoresPorEquipo.
*/
int getidEquipo(JugadoresPorEquipo &jugadoresPorEquipo);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el idJugador de jugadoresPorEquipo.
*/
int getidJugador(JugadoresPorEquipo &jugadoresPorEquipo);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de id a la instancia.
*/
void setIdEquipo(JugadoresPorEquipo &jugadoresPorEquipo, int id);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de id a la instancia.
*/
void setIdJugador(JugadoresPorEquipo &jugadoresPorEquipo, int id);


#endif // JUGADORESPOREQUIPO_H_INCLUDED
