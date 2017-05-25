#include "equipo.h"


void crear(Equipo &equipo){

    equipo.id=0;
    equipo.nombre= "x";
    equipo.nombreUsuario= "x";
    crearLista(equipo.jugadores);
    equipo.puntajeFecha=0;
    equipo.puntajeTotal=0;
}

int getId(Equipo &equipo){
    return equipo.id;
}

char* getNombre(Equipo &equipo){
    return equipo.nombre;
}

char* getNombreUsuario(Equipo &equipo){
    return equipo.nombreUsuario;
}

ListaJugador getJugadores(Equipo &equipo){
    return equipo.jugadores;
}

int getPuntajeFecha(Equipo &equipo){
    return equipo.puntajeFecha;
}

int getPuntajeTotal(Equipo &equipo){
    return equipo.puntajeTotal;
}

void setId(Equipo &equipo,int id){
    equipo.id=id;
}

void setNombre (Equipo &equipo, char*nombre){
    equipo.nombreUsuario=nombre;
}

void setNombreUsuario (Equipo &equipo, char*nombre){
    equipo.nombre=nombre;
}
