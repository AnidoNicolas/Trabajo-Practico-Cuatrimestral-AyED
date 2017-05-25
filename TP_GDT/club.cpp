#include "club.h"

void crear(club &club){
    club.idClub=0;
    club.nombre="x";
}

int getIdClub(club &club){
    return club.idClub;
}

char* getNombre(club &club){
    return club.nombre;
}


