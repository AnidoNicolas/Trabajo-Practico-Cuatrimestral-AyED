#ifndef __JUGADOR_H__
#define __JUGADOR_H__

enum Posicion{ARQ,DEF,MED,DEL};

struct Jugador{
    int id;
    char* nombre;
    Posicion posision;
    float precio;
    int puntajeFecha;
    int puntajeTotal;
};

//////////PRIMITIVAS

void crear(Jugador &jugador);

void setNombre(Jugador &Jugador, char *nom);

int getId(Jugador &jugador);

char* getNombre(Jugador &jugador);

Posicion getPosicion (Jugador &jugador);

float getPrecio (Jugador &jugador);

int getPuntajeFecha(Jugador &jugador);

int getPuntajeTotal(Jugador &jugador);

#endif // __JUGADOR_H__
