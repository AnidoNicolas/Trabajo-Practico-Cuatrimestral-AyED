#ifndef PUNTAJEFECHA_H_INCLUDED
#define PUNTAJEFECHA_H_INCLUDED


typedef struct  {

    int idJugador;
    int fecha;
    int puntos;

} puntajesPorJugador;

void crear(puntajesPorJugador &puntajesPorJugador);

void destruir(puntajesPorJugador &puntajesPorJugador);

int getIdJugador(puntajesPorJugador &puntajesPorJugador);

int getFecha(puntajesPorJugador &puntajesPorJugador);

int getPuntos(puntajesPorJugador &puntajesPorJugador);

void setIdJugador(puntajesPorJugador &puntajesPorJugador, int id);

void setFecha(puntajesPorJugador &puntajesPorJugador,int fecha);

void setPuntos(puntajesPorJugador &puntajesPorJugador,int puntos);

#endif // PUNTAJEFECHA_H_INCLUDED
