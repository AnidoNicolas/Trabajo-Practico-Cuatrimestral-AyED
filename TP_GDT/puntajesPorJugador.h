#ifndef PUNTAJEFECHA_H_INCLUDED
#define PUNTAJEFECHA_H_INCLUDED


typedef struct  {

    int idJugador;
    int fecha;
    int puntos;

} puntajesPorJugador;

//////////PRIMITIVAS

/*
    Pre: El TDA no debe haber sido creado con anteridad.
    Post: Crea el TDA con los siguientes valores:
         idJugador=0; fecha=0; puntos=0.
*/
void crear(puntajesPorJugador &puntajesPorJugador);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Destruye la instancia del TDA y ya no podrá ser utilizada.
*/
void destruir(puntajesPorJugador &puntajesPorJugador);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el idJugador de puntajesPorJugador.
*/
int getIdJugador(puntajesPorJugador &puntajesPorJugador);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve la fecha de puntajesPorJugador.
*/
int getFecha(puntajesPorJugador &puntajesPorJugador);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve los puntos de puntajesPorJugador.
*/
int getPuntos(puntajesPorJugador &puntajesPorJugador);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de id a la instancia.
*/
void setIdJugador(puntajesPorJugador &puntajesPorJugador, int id);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de fecha a la instancia.
*/
void setFecha(puntajesPorJugador &puntajesPorJugador,int fecha);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de puntos a la instancia.
*/
void setPuntos(puntajesPorJugador &puntajesPorJugador,int puntos);

#endif // PUNTAJEFECHA_H_INCLUDED
