#ifndef CLUB_H_INCLUDED
#define CLUB_H_INCLUDED

typedef struct  {
    int idClub;
    char* nombre;
}Club;

void crear(Club &club);

void destruir(Club &club);

int getIdClub(Club &club);

char* getNombre(Club &club);

void setId(Club &club, int id);

void setNombre(Club &club, char* nombre);

#endif // CLUB_H_INCLUDED
