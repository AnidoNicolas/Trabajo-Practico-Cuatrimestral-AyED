#include "jugadoresPorEquipo.h"

void crear(JugadoresPorEquipo &jugadoresPorEquipo){
    jugadoresPorEquipo.idJugador=0;
    jugadoresPorEquipo.idEquipo=0;
}

int getidEquipo(JugadoresPorEquipo &jugadoresPorequipo){
    return jugadoresPorequipo.idEquipo;
}

int getidJugador(JugadoresPorEquipo &jugadoresPorequipo){
    return jugadoresPorequipo.idJugador;
}

void setIdEquipo(JugadoresPorEquipo &jugadoresPorEquipo, int id){
    jugadoresPorEquipo.idEquipo=id;
}

void setIdJugador(JugadoresPorEquipo &jugadoresPorEquipo, int id){
    jugadoresPorEquipo.idJugador=id;
}
