#ifndef __JUGADOR_H__
#define __JUGADOR_H__

enum Posicion{ARQ,DEF,MED,DEL};

struct Jugador{
    int id;
    char* nombre;
    int idClub;
    Posicion posision;
    float precio;
    int puntajeFecha;
    int puntajeTotal;
};

//////////PRIMITIVAS

void crear(Jugador &jugador);

void setNombre(Jugador &Jugador, char *nom);

void setId(Jugador &jugador, int id);

void setIdClub(Jugador &Jugador, int id);

void setPosicion(Jugador &jugador, Posicion posicion);

void setPrecio(Jugador &jugador, float precio);

void setPuntajeFecha(Jugador &jugador, int puntaje);

void setPuntajeTotal(Jugador &jugador, int puntaje);

int getId(Jugador &jugador);

char* getNombre(Jugador &jugador);

int getIdClub(Jugador &jugador);

Posicion getPosicion (Jugador &jugador);

float getPrecio (Jugador &jugador);

int getPuntajeFecha(Jugador &jugador);

int getPuntajeTotal(Jugador &jugador);

#endif // __JUGADOR_H__
