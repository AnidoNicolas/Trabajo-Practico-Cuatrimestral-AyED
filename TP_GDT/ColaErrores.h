#include "error.h"
#ifndef NULL
#define NULL      0
#endif // NULL

/* Tipo de Informacion que esta contenida en los Nodos de la
   Cola, identificada como Dato. */
typedef Error DatoError;

/* Tipo de Estructura de los Nodos de la Cola. */
struct NodoError {
    DatoError datoError; // puntero al dato almacenado
    NodoError* ant; // puntero al anterior
};

/* Tipo de Puntero a los Nodos de la Cola, el cual se usa para trabajar
    sobre la Cola y acceder a sus Datos. */
typedef NodoError* PtrNodoError;


/* Tipo de Estructura de la Cola */
struct Cola{
    PtrNodoError primero;      // puntero al primer nodo de la cola
    PtrNodoError ultimo;
    int longitud;
};


void crear(Cola &cola);

void destruir(Cola &cola);

DatoError desncolar(Cola &cola);

void encolar(Cola &cola, DatoError dato);

bool colaVacia(Cola &cola);

PtrNodoError crearNodoCola(DatoError dato);

PtrNodoError finError();

