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
/*
    Pre: El TDA no debe haber sido creado con anteridad.
    Post: Crea el TDA con los siguientes valores:
         id=0; nombre="x"; idClub= 0;
         posicion= ARQ; precio=0.0; puntajeFecha=0;puntajeTotal=0
*/
void crear(Jugador &jugador);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de nombre  a la instancia.
*/
void setNombre(Jugador &Jugador, char *nom);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de id a la instancia.
*/
void setId(Jugador &jugador, int id);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de id a la instancia.
*/
void setIdClub(Jugador &Jugador, int id);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de posicion a la instancia.
*/
void setPosicion(Jugador &jugador, Posicion posicion);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de precio a la instancia.
*/
void setPrecio(Jugador &jugador, float precio);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de puntaje a la instancia.
*/
void setPuntajeFecha(Jugador &jugador, int puntaje);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de puntaje a la instancia.
*/
void setPuntajeTotal(Jugador &jugador, int puntaje);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el id de jugador.
*/
int getId(Jugador &jugador);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el nombre que esta en la direccion de memoria.
*/
char* getNombre(Jugador &jugador);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el idClub de jugador.
*/
int getIdClub(Jugador &jugador);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve la posicion de jugador.
*/
Posicion getPosicion (Jugador &jugador);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el precio de jugador.
*/
float getPrecio (Jugador &jugador);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el Puntaje por Fecha de jugador.
*/
int getPuntajeFecha(Jugador &jugador);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el Puntaje Total de jugador.
*/
int getPuntajeTotal(Jugador &jugador);

#endif // __JUGADOR_H__
