#include "listaJugadores.h"

/******************************************************************************/
/* Definición de Tipos de Datos para manejo interno */
/*--------------------------------------------------*/


/******************************************************************************/
/* Funciones Adicionales */
/*-----------------------*/

/*
  pre : ninguna.
  post: compara ambos dato1 y dato2, devuelve
          mayor si dato1 es mayor que dato2,
          igual si dato1 es igual a dato2,
          menor si dato1 es menor que dato2.

  dato1 : dato a comparar.
  dato2 : dato a comparar.
  return resultado de comparar dato1 respecto de dato2.
*/

ResultadoComparacion compararDato(Dato dato1, Dato dato2) {
    if (dato1.puntajeFecha > dato2.puntajeFecha) {
        return MAYOR;
    }
    else if (dato1.puntajeFecha < dato2.puntajeFecha) {
        return MENOR;
    }
    else {
        return IGUAL;
    }
}


/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

void crearLista(ListaJugador &lista) {
  lista.primero = finJugadores();
}

/*----------------------------------------------------------------------------*/
bool listaVacia(ListaJugador &lista) {

  return (primero(lista) == finJugadores());
}

/*----------------------------------------------------------------------------*/

PtrNodoLista finJugadores() {
  return NULL;
}



/*----------------------------------------------------------------------------*/
PtrNodoLista primero(ListaJugador &lista) {
  return lista.primero;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista siguiente(ListaJugador &lista, PtrNodoLista ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVacia(lista)) && (ptrNodo != finJugadores()))
    return ptrNodo->sgte;
  else
    return finJugadores();
}

/*----------------------------------------------------------------------------*/
PtrNodoLista anterior(ListaJugador &lista, PtrNodoLista ptrNodo) {

  PtrNodoLista ptrPrevio = finJugadores();
  PtrNodoLista ptrCursor = primero(lista);

  while (( ptrCursor != finJugadores()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista ultimo(ListaJugador &lista) {

  /* el último nodo de la lista es el anterior al fin() */
  return anterior(lista,finJugadores());
}

/*----------------------------------------------------------------------------*/
PtrNodoLista crearNodoLista(Dato dato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoLista ptrAux = new NodoLista;

  ptrAux->dato = dato;
  ptrAux->sgte = finJugadores();

  return ptrAux;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarPrincipio(ListaJugador &lista, Dato dato) {

  /* crea el nodo */
  PtrNodoLista ptrNuevoNodo = crearNodoLista(dato);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarDespues(ListaJugador &lista, Dato dato, PtrNodoLista ptrNodo) {

  PtrNodoLista ptrNuevoNodo = finJugadores();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,dato);

  else {
    if (ptrNodo != finJugadores()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(dato);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarFinal(ListaJugador &lista, Dato dato) {

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,dato,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarAntes(ListaJugador &lista, Dato dato, PtrNodoLista ptrNodo) {

  PtrNodoLista ptrNuevoNodo = finJugadores();

  if (! listaVacia(lista)) {
    if (ptrNodo != primero(lista))
      ptrNuevoNodo = adicionarDespues(lista,dato,anterior(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(lista,dato);
   }
   return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
void colocarDato(ListaJugador &lista, Dato &dato, PtrNodoLista ptrNodo) {

  if ( (! listaVacia(lista)) && (ptrNodo != finJugadores()))
     ptrNodo->dato = dato;
}

/*----------------------------------------------------------------------------*/
void obtenerDato(ListaJugador &lista, Dato &dato, PtrNodoLista ptrNodo) {

  if ((! listaVacia(lista)) && (ptrNodo != finJugadores()))
    dato = ptrNodo->dato;
}

/*----------------------------------------------------------------------------*/
void eliminarNodo(ListaJugador &lista, PtrNodoLista ptrNodo) {

  PtrNodoLista ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(lista)) && (ptrNodo != finJugadores())) {

    if (ptrNodo == primero(lista))
      lista.primero = siguiente(lista,primero(lista));

    else {
      ptrPrevio = anterior( lista , ptrNodo );
      ptrPrevio->sgte = ptrNodo->sgte;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.

    delete ptrNodo;
  }
}

/*----------------------------------------------------------------------------*/
void eliminarNodoPrimero(ListaJugador &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(ListaJugador &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarLista(ListaJugador &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoLista localizarDato(ListaJugador &lista, Dato dato) {

   bool encontrado = false;
   Dato datoCursor;
   PtrNodoLista ptrCursor = primero(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != finJugadores()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerDato(lista,datoCursor,ptrCursor);
    if (compararDato(datoCursor,dato) == IGUAL)
      encontrado = true;
    else
      ptrCursor = siguiente(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = finJugadores();

  return ptrCursor;
}

/*----------------------------------------------------------------------------*/
void eliminarDato(ListaJugador &lista, Dato dato) {

  /* localiza el dato y luego lo elimina */
  PtrNodoLista ptrNodo = localizarDato(lista,dato);
  if (ptrNodo != finJugadores())
    eliminarNodo(lista,ptrNodo);
}

/*----------------------------------------------------------------------------*/
PtrNodoLista insertarDato(ListaJugador &lista, Dato dato) {

  PtrNodoLista ptrPrevio = primero(lista);
  PtrNodoLista ptrCursor = primero(lista);
  PtrNodoLista ptrNuevoNodo;
  Dato datoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != finJugadores()) && (! ubicado)) {

    obtenerDato(lista,datoCursor,ptrCursor);
    if (compararDato(datoCursor,dato) == MAYOR)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguiente(lista,ptrCursor);
    }
  }

  if (ptrCursor == primero(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,dato);
  else
    ptrNuevoNodo = adicionarDespues(lista,dato,ptrPrevio);

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/

void reordenar(ListaJugador &lista) {

  ListaJugador temp = lista;
  PtrNodoLista ptrCursor = primero(temp);
  crearLista(lista);
  while ( ptrCursor != finJugadores() ) {
        Dato dato;
        obtenerDato( temp, dato, ptrCursor);
        insertarDato( lista, dato );
        eliminarNodo( temp, ptrCursor );
        ptrCursor = primero(temp);
  }
  eliminarLista( temp );
}

/*----------------------------------------------------------------------------*/

int longitud(ListaJugador &lista){
  PtrNodoLista ptrCursor = primero(lista);
  int longitud = 0;
  while ( ptrCursor != finJugadores() ) {
        longitud++;
        ptrCursor = siguiente( lista, ptrCursor);
  }
  return longitud;
}

/*----------------------------------------------------------------------------*/
