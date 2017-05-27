#include "listaJugadoresPorEquipo.h"
#ifndef NULL
#define NULL      0
#endif
/******************************************************************************/
/* Implementación de Primitivas */

ResultadoComparacion compararDato(DatoJxE dato1, DatoJxE dato2) {
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

void crearLista(listaJxE &lista) {
  lista.primero = finJxE();
}

/*----------------------------------------------------------------------------*/
bool listaVacia(listaJxE &lista) {

  return (primero(lista) == finJxE());
}

PtrNodoListaJxE finJxE() {
  return NULL;
}

/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
PtrNodoListaJxE primero(listaJxE &lista) {
  return lista.primero;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJxE siguiente(listaJxE&lista, PtrNodoListaJxE ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVacia(lista)) && (ptrNodo != finJxE()))
    return ptrNodo->sgte;
  else
    return finJxE();
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJxE anterior(listaJxE &lista, PtrNodoListaJxE ptrNodo) {

  PtrNodoListaJxE ptrPrevio = finJxE();
  PtrNodoListaJxE ptrCursor = primero(lista);

  while (( ptrCursor != finJxE()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJxE ultimo(listaJxE &lista) {

  /* el último nodo de la lista es el anterior al fin() */
  return anterior(lista,finJxE());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJxE crearNodoLista(DatoJxE dato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoListaJxE ptrAux = new NodoListaJxE;

  ptrAux->dato = dato;
  ptrAux->sgte = finJxE();

  return ptrAux;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJxE adicionarPrincipio(listaJxE &lista, DatoJxE dato) {

  /* crea el nodo */
  PtrNodoListaJxE ptrNuevoNodo = crearNodoLista(dato);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJxE adicionarDespues(listaJxE &lista, DatoJxE dato, PtrNodoListaJxE ptrNodo) {

  PtrNodoListaJxE ptrNuevoNodo = finJxE();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,dato);

  else {
    if (ptrNodo != finJxE()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(dato);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJxE adicionarFinal(listaJxE &lista, DatoJxE dato) {

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,dato,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJxE adicionarAntes(listaJxE &lista, DatoJxE dato, PtrNodoListaJxE ptrNodo) {

  PtrNodoListaJxE ptrNuevoNodo = finJxE();

  if (! listaVacia(lista)) {
    if (ptrNodo != primero(lista))
      ptrNuevoNodo = adicionarDespues(lista,dato,anterior(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(lista,dato);
   }
   return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
void colocarDato(listaJxE &lista, DatoJxE &dato, PtrNodoListaJxE ptrNodo) {

  if ( (! listaVacia(lista)) && (ptrNodo != finJxE()))
     ptrNodo->dato = dato;
}

/*----------------------------------------------------------------------------*/
void obtenerDato(listaJxE &lista, DatoJxE &dato, PtrNodoListaJxE ptrNodo) {

  if ((! listaVacia(lista)) && (ptrNodo != finJxE()))
    dato = ptrNodo->dato;
}

/*----------------------------------------------------------------------------*/
void eliminarNodo(listaJxE &lista, PtrNodoListaJxE ptrNodo) {

  PtrNodoListaJxE ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(lista)) && (ptrNodo != finJxE())) {

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
void eliminarNodoPrimero(listaJxE &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(listaJxE &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarLista(listaJxE &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJxE localizarDato(listaJxE &lista, DatoJxE dato) {

   bool encontrado = false;
   DatoJxE datoCursor;
   PtrNodoListaJxE ptrCursor = primero(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != finJxE()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerDato(lista,datoCursor,ptrCursor);
    if (compararDato(datoCursor,dato) == IGUAL)
      encontrado = true;
    else
      ptrCursor = siguiente(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = finJxE();

  return ptrCursor;
}

/*----------------------------------------------------------------------------*/
void eliminarDato(listaJxE &lista, DatoJxE dato) {

  /* localiza el dato y luego lo elimina */
  PtrNodoListaJxE ptrNodo = localizarDato(lista,dato);
  if (ptrNodo != finJxE())
    eliminarNodo(lista,ptrNodo);
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJxE insertarDato(listaJxE &lista, DatoJxE dato) {

  PtrNodoListaJxE ptrPrevio = primero(lista);
  PtrNodoListaJxE ptrCursor = primero(lista);
  PtrNodoListaJxE ptrNuevoNodo;
  DatoJxE datoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != finJxE()) && (! ubicado)) {

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

void reordenar(listaJxE &lista) {

  listaJxE temp = lista;
  PtrNodoListaJxE ptrCursor = primero(temp);
  crearLista(lista);
  while ( ptrCursor != finJxE() ) {
        DatoJxE dato;
        obtenerDato( temp, dato, ptrCursor);
        insertarDato( lista, dato );
        eliminarNodo( temp, ptrCursor );
        ptrCursor = primero(temp);
  }
  eliminarLista( temp );
}

/*----------------------------------------------------------------------------*/

int longitud(listaJxE &lista){
  PtrNodoListaJxE ptrCursor = primero(lista);
  int longitud = 0;
  while ( ptrCursor != finJxE() ) {
        longitud++;
        ptrCursor = siguiente( lista, ptrCursor);
  }
  return longitud;
}
/*------------------------------*/
