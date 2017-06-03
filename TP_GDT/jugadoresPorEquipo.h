#ifndef JUGADORESPOREQUIPO_H_INCLUDED
#define JUGADORESPOREQUIPO_H_INCLUDED

struct JugadoresPorEquipo{
    int idEquipo;
    int idJugador;
};

void crear(JugadoresPorEquipo &jugadoresPorEquipo);

int getidEquipo(JugadoresPorEquipo &jugadoresPorEquipo);

int getidJugador(JugadoresPorEquipo &jugadoresPorEquipo);

void setIdEquipo(JugadoresPorEquipo &jugadoresPorEquipo, int id);

void setIdJugador(JugadoresPorEquipo &jugadoresPorEquipo, int id);


#endif // JUGADORESPOREQUIPO_H_INCLUDED
