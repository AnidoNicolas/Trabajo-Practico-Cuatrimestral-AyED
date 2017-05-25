#include "puntajesPorJugador.h"

void crear(puntajesPorJugador &puntajesPorJugador){
    puntajesPorJugador.idJugador=0;
    puntajesPorJugador.fecha=0;
    puntajesPorJugador.puntos=0;
}

int getIdJugador(puntajesPorJugador &puntajesPorJugador){
    return puntajesPorJugador.idJugador;
}

int getFecha(puntajesPorJugador &puntajesPorJugador){
    return puntajesPorJugador.fecha;
}

int getPuntos(puntajesPorJugador &puntajesPorJugador){
    return puntajesPorJugador.puntos;
}
