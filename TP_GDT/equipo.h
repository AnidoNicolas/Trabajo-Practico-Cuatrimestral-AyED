#include "listaJugadores.h"
#ifndef __EQUIPOS_H__
#define __EQUIPOS_H__

struct Equipo{
    int id;
    char* nombre;
    char* nombreUsuario;
    ListaJugador jugadores;
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

int getId(Equipo &equipo);

char* getNombre(Equipo &equipo);

char* getNombreUsuario(Equipo &equipo);

ListaJugador getJugadores(Equipo &equipo);

int getPuntajeFecha(Equipo &equipo);

int getPuntajeTotal(Equipo &equipo);

void setId(Equipo &equipo,int id);

void setNombre (Equipo &equipo, char*nombre);

void setNombreUsuario (Equipo &equipo, char*nombre);

void setPuntajeFecha(Equipo &equipo,int puntaje);
#endif // __EQUIPOS_H__
