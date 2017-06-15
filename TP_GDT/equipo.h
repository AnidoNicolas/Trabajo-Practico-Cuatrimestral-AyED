#include "listaJugadores.h"
#ifndef __EQUIPOS_H__
#define __EQUIPOS_H__

struct Equipo{
    int id;
    char* nombre;
    char* nombreUsuario;
    ListaJugador* jugadores;
    int puntajeFecha;
    int puntajeTotal;
};

////////// PRIMITIVAS
/*
    Pre: El TDA no debe haber sido creado con anteridad.
    Post: Crea el TDA con los siguientes valores:
         id=0; nombre=Puntero al nombre; nombreUsuario= puntero al Nombre del usuario
         jugadores= Puntero al jugador; puntajeFecha=0; puntajeTotal=0;
*/
void crear(Equipo &equipo);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el id del equipo.
*/
int getId(Equipo &equipo);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el nombre que esta en la direccion de memoria.
*/
char* getNombre(Equipo &equipo);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el nombre de usuario que esta en la direccion de memoria.
*/
char* getNombreUsuario(Equipo &equipo);

ListaJugador* getJugadores(Equipo &equipo);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el puntaje por fecha del equipo.
*/
int getPuntajeFecha(Equipo &equipo);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el puntaje total del equipo.
*/
int getPuntajeTotal(Equipo &equipo);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de id a la instancia.
*/
void setId(Equipo &equipo,int id);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de nombre  a la instancia.
*/
void setNombre (Equipo &equipo, char*nombre);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de nombre a la instancia.
*/
void setNombreUsuario (Equipo &equipo, char*nombre);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de puntaje a la instancia.
*/
void setPuntajeFecha(Equipo &equipo,int puntaje);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de puntaje a la instancia.
*/
void setPuntajeTotal(Equipo &equipo, int puntaje);
#endif // __EQUIPOS_H__
