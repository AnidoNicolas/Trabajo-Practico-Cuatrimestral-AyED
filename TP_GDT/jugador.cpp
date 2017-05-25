#include "jugador.h"

void crear(Jugador &jugador){
    jugador.id=0;
    jugador.nombre="x";
    jugador.posision=ARQ;
    jugador.precio=0.0;
    jugador.puntajeFecha=0;
    jugador.puntajeTotal=0;
}

void setNombre(Jugador &jugador, char *nom){
    jugador.nombre= nom;
}

int getId(Jugador &jugador){
    return jugador.id;
}

char* getNombre(Jugador &jugador){
    return jugador.nombre;
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
