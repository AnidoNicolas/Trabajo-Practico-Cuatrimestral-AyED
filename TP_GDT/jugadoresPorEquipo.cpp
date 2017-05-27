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
