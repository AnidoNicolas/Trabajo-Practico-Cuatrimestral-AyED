#include "club.h"

void crear(Club &club){
    club.idClub=0;
    club.nombre="x";
}

int getIdClub(Club &club){
    return club.idClub;
}

char* getNombre(Club &club){
    return club.nombre;
}

void setId(Club &club, int id){
    club.idClub=id;
}

void setNombre(Club &club, char*nombre){
    club.nombre=nombre;
}


