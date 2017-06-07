#include "error.h"

void crear(Error &error){
    error.idError=0;
    error.descripcion="x";
}

int getIdError(Error &error){
    return error.idError;
}

char* getDescripcion(Error &error){
    return error.descripcion;
}

void setIdError(Error &error, int id){
    error.idError=id;
}

void setDescripcion(Error &error, char* descripcion){
    error.descripcion= descripcion;
}
