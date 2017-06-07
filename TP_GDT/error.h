#ifndef __ERROR_H__
#define __ERROR_H__

struct Error{
    int idError;
    char* descripcion;
};

void crear(Error &error);

int getIdError(Error &error);

char* getDescripcion(Error &error);

void setIdError(Error &error, int id);

void setDescripcion(Error &error, char* descripcion);

#endif // __ERROR_H__
