#ifndef __ERROR_H__
#define __ERROR_H__

struct Error{
    int NumeroError;
    char* descripcion;
};

void crear(Error &error);

int getNumeroError(Error &error);

char* getDescripcion(Error &error);

void setNumeroError(Error &error, int numero);

void setDescripcion(Error &error, char* descripcion);

#endif // __ERROR_H__
