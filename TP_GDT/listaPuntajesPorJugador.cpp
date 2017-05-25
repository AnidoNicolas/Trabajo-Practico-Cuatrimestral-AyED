/* TDA Lista
 * Implementación Simplemente Enlazada
 * Archivo : Lista.cpp
 * Versión : 1.1
 */


#include "listaPuntajesPorJugador.h"

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


ResultadoComparacion compararDato(DatoPJ dato1, DatoPJ dato2) {
    if (dato1.idJugador > dato2.idJugador) {
        return MAYOR;
    }
    else if (dato1.idJugador< dato2.idJugador) {
        return MENOR;
    }
    else {
        return IGUAL;
    }
}




/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

void crearLista(listaPJ &lista) {
  lista.primero = finPJ();
}

/*----------------------------------------------------------------------------*/
bool listaVacia(listaPJ &lista) {

  return (primero(lista) == finPJ());
}

PtrNodoListaPJ finPJ() {
  return NULL;
}

/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
PtrNodoListaPJ primero(listaPJ &lista) {
  return lista.primero;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPJ siguiente(listaPJ&lista, PtrNodoListaPJ ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVacia(lista)) && (ptrNodo != finPJ()))
    return ptrNodo->sgte;
  else
    return finPJ();
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPJ anterior(listaPJ &lista, PtrNodoListaPJ ptrNodo) {

  PtrNodoListaPJ ptrPrevio = finPJ();
  PtrNodoListaPJ ptrCursor = primero(lista);

  while (( ptrCursor != finPJ()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPJ ultimo(listaPJ &lista) {

  /* el último nodo de la lista es el anterior al fin() */
  return anterior(lista,finPJ());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPJ crearNodoLista(DatoPJ dato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoListaPJ ptrAux = new NodoListaPJ;

  ptrAux->dato = dato;
  ptrAux->sgte = finPJ();

  return ptrAux;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPJ adicionarPrincipio(listaPJ &lista, DatoPJ dato) {

  /* crea el nodo */
  PtrNodoListaPJ ptrNuevoNodo = crearNodoLista(dato);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPJ adicionarDespues(listaPJ &lista, DatoPJ dato, PtrNodoListaPJ ptrNodo) {

  PtrNodoListaPJ ptrNuevoNodo = finPJ();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,dato);

  else {
    if (ptrNodo != finPJ()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(dato);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPJ adicionarFinal(listaPJ &lista, DatoPJ dato) {

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,dato,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPJ adicionarAntes(listaPJ &lista, DatoPJ dato, PtrNodoListaPJ ptrNodo) {

  PtrNodoListaPJ ptrNuevoNodo = finPJ();

  if (! listaVacia(lista)) {
    if (ptrNodo != primero(lista))
      ptrNuevoNodo = adicionarDespues(lista,dato,anterior(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(lista,dato);
   }
   return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
void colocarDato(listaPJ &lista, DatoPJ &dato, PtrNodoListaPJ ptrNodo) {

  if ( (! listaVacia(lista)) && (ptrNodo != finPJ()))
     ptrNodo->dato = dato;
}

/*----------------------------------------------------------------------------*/
void obtenerDato(listaPJ &lista, DatoPJ &dato, PtrNodoListaPJ ptrNodo) {

  if ((! listaVacia(lista)) && (ptrNodo != finPJ()))
    dato = ptrNodo->dato;
}

/*----------------------------------------------------------------------------*/
void eliminarNodo(listaPJ &lista, PtrNodoListaPJ ptrNodo) {

  PtrNodoListaPJ ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(lista)) && (ptrNodo != finPJ())) {

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
void eliminarNodoPrimero(listaPJ &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(listaPJ &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarLista(listaPJ &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPJ localizarDato(listaPJ &lista, DatoPJ dato) {

   bool encontrado = false;
   DatoPJ datoCursor;
   PtrNodoListaPJ ptrCursor = primero(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != finPJ()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerDato(lista,datoCursor,ptrCursor);
    if (compararDato(datoCursor,dato) == IGUAL)
      encontrado = true;
    else
      ptrCursor = siguiente(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = finPJ();

  return ptrCursor;
}

/*----------------------------------------------------------------------------*/
void eliminarDato(listaPJ &lista, DatoPJ dato) {

  /* localiza el dato y luego lo elimina */
  PtrNodoListaPJ ptrNodo = localizarDato(lista,dato);
  if (ptrNodo != finPJ())
    eliminarNodo(lista,ptrNodo);
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPJ insertarDato(listaPJ &lista, DatoPJ dato) {

  PtrNodoListaPJ ptrPrevio = primero(lista);
  PtrNodoListaPJ ptrCursor = primero(lista);
  PtrNodoListaPJ ptrNuevoNodo;
  DatoPJ datoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != finPJ()) && (! ubicado)) {

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

void reordenar(listaPJ &lista) {

  listaPJ temp = lista;
  PtrNodoListaPJ ptrCursor = primero(temp);
  crearLista(lista);
  while ( ptrCursor != finPJ() ) {
        DatoPJ dato;
        obtenerDato( temp, dato, ptrCursor);
        insertarDato( lista, dato );
        eliminarNodo( temp, ptrCursor );
        ptrCursor = primero(temp);
  }
  eliminarLista( temp );
}

/*----------------------------------------------------------------------------*/

int longitud(listaPJ &lista){
  PtrNodoListaPJ ptrCursor = primero(lista);
  int longitud = 0;
  while ( ptrCursor != finPJ() ) {
        longitud++;
        ptrCursor = siguiente( lista, ptrCursor);
  }
  return longitud;
}
