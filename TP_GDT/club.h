#ifndef CLUB_H_INCLUDED
#define CLUB_H_INCLUDED

typedef struct  {
    int idClub;
    char* nombre;
}club;

void crear(club &club);

void destruir(club &club);

int getIdClub(club &club);

char* getNombre(club &club);

#endif // CLUB_H_INCLUDED
