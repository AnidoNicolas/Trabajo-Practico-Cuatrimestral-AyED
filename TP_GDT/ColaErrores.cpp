#include "ColaErrores.h"


void crear(Cola &cola){
    cola.primero=finError();
    cola.ultimo=finError();
    cola.longitud=0;
}
void encolar(Cola &cola, DatoError dato){
    PtrNodoError PtrNuevoNodo = crearNodoCola(dato);
    if(colaVacia(cola)){
        cola.primero=PtrNuevoNodo;
        cola.ultimo=PtrNuevoNodo;
        cola.longitud=1;
    }
    else{
        cola.ultimo->ant=PtrNuevoNodo;
        cola.ultimo=PtrNuevoNodo;
        cola.longitud+=1;
    }
}

bool colaVacia(Cola &cola){
    return(cola.primero==finError()&&cola.ultimo==finError());
}

PtrNodoError crearNodoCola(DatoError dato) {
  PtrNodoError ptrAux = new NodoError;
  ptrAux->datoError = dato;
  ptrAux->ant = finError();
  return ptrAux;
}

void destruir(Cola &cola){

}

DatoError desncolar(Cola &cola){
    DatoError dato = cola.primero->datoError;
    PtrNodoError aux = cola.primero;
    cola.primero= cola.primero->ant;
    cola.longitud-=1;
    delete aux;
    return dato;
}

PtrNodoError finError(){
    return NULL;
}
