#include "error.h"

void crear(Error &error){
    error.NumeroError=0;
    error.descripcion="x";
}

int getIdError(Error &error){
    return error.NumeroError;
}

char* getDescripcion(Error &error){
    return error.descripcion;
}

void setIdError(Error &error, int numero){
    error.NumeroError=numero;
}

void setDescripcion(Error &error, char* descripcion){
    error.descripcion= descripcion;
}
