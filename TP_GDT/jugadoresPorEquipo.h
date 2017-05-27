#ifndef JUGADORESPOREQUIPO_H_INCLUDED
#define JUGADORESPOREQUIPO_H_INCLUDED

struct JugadoresPorEquipo{
    int idEquipo;
    int idJugador;
};

void crear(JugadoresPorEquipo &jugadoresPorEquipo);

int getidEquipo(JugadoresPorEquipo &jugadoresPorEquipo);

int getidJugador(JugadoresPorEquipo &jugadoresPorEquipo);


#endif // JUGADORESPOREQUIPO_H_INCLUDED
