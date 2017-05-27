#ifndef JUGADORESPOREQUIPO_H_INCLUDED
#define JUGADORESPOREQUIPO_H_INCLUDED

struct jugadoresPorEquipo{
    int idEquipo;
    int idJugador;
};

void crear(JugadoresPorEquipo &jugadoresPorEquipo);

int getidEquipo(JugadoresPorEquipo &jugadoresPorEquipo);

int getidJugador(jugadoresPorEquipo &jugadoresPorEquipo);


#endif // JUGADORESPOREQUIPO_H_INCLUDED
