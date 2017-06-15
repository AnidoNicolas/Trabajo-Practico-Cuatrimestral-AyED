#ifndef CLUB_H_INCLUDED
#define CLUB_H_INCLUDED

typedef struct  {
    int idClub;
    char* nombre;
}Club;

/**
PRE:
    La instancia del TDA  no debe haberse creado (crear) ni destruido (destruir) con anterioridad.
POST:
    Deja la instancia del TDA listo para ser usado. Crea el TDA  con los siguientes valores: idClub=0; nombre="x".
*/
void crear(Club &club);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Destruye la instancia del TDA y ya no podrá ser utilizada.
*/
void destruir(Club &club);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el id del club.
*/
int getIdClub(Club &club);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    devuelve el nombre que esta en la direccion de memoria.
*/
char* getNombre(Club &club);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de id a la instancia.
*/
void setId(Club &club, int id);

/**
PRE:
    La instancia del TDA debe haberse creado con anterioridad (primitiva crear) y nunca se ejecutó la primitiva destruir sobre esta instancia.
POST:
    Asigna el valor de nombre  a la instancia.
*/
void setNombre(Club &club, char* nombre);

#endif // CLUB_H_INCLUDED
