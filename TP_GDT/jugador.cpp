#include "jugador.h"

void crear(Jugador &jugador){
    jugador.id=0;
    jugador.nombre="x";
    jugador.idClub=0;
    jugador.posision=ARQ;
    jugador.precio=0.0;
    jugador.puntajeFecha=0;
    jugador.puntajeTotal=0;
}

void setNombre(Jugador &jugador, char *nom){
    jugador.nombre= nom;
}

void setId(Jugador &jugador, int id){
    jugador.id=id;
}

void setIdClub(Jugador &Jugador, int id){
    Jugador.idClub=id;
}

void setPosicion(Jugador &jugador, Posicion posicion){
    jugador.posision=posicion;
}

void setPrecio(Jugador &jugador, float precio){
    jugador.precio=precio;
}

void setPuntajeFecha(Jugador &jugador, int puntaje){
    jugador.puntajeFecha=puntaje;
}

void setPuntajeTotal(Jugador &jugador, int puntaje){
    jugador.puntajeTotal=puntaje;
}

int getId(Jugador &jugador){
    return jugador.id;
}

char* getNombre(Jugador &jugador){
    return jugador.nombre;
}

int getIdClub(Jugador &jugador){
    return jugador.idClub;
}

Posicion getPosicion (Jugador &jugador){
    return jugador.posision;
}

float getPrecio (Jugador &jugador){
    return jugador.precio;
}
int getPuntajeFecha(Jugador &jugador){
    return jugador.puntajeFecha;
}

int getPuntajeTotal(Jugador &jugador){
    return jugador.puntajeTotal;
}
