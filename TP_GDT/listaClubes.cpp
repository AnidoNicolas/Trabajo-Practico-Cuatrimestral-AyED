/* TDA Lista Clubes
 * Implementación Simplemente Enlazada
 * Archivo : ListaClubes.cpp*/



#include "listaClubes.h"

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

ResultadoComparacion compararDato(DatoCl dato1, DatoCl dato2) {
    if (dato1.idClub > dato2.idClub) {
        return MAYOR;
    }
    else if (dato1.idClub< dato2.idClub) {
        return MENOR;
    }
    else {
        return IGUAL;
    }
}


/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

void crearLista(listaClubes &lista) {
  lista.primero = fin();
}

/*----------------------------------------------------------------------------*/
bool listaVacia(listaClubes &lista) {

  return (primero(lista) == fin());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaCl fin() {
  return NULL;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaCl primero(listaClubes &lista) {
  return lista.primero;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaCl siguiente(listaClubes&lista, PtrNodoListaCl ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVacia(lista)) && (ptrNodo != fin()))
    return ptrNodo->sgte;
  else
    return fin();
}

/*----------------------------------------------------------------------------*/
PtrNodoListaCl anterior(listaClubes &lista, PtrNodoListaCl ptrNodo) {

  PtrNodoListaCl ptrPrevio = fin();
  PtrNodoListaCl ptrCursor = primero(lista);

  while (( ptrCursor != fin()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaCl ultimo(listaClubes &lista) {

  /* el último nodo de la lista es el anterior al fin() */
  return anterior(lista,fin());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaCl crearNodoLista(DatoCl dato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoListaCl ptrAux = new NodoListaCl;

  ptrAux->dato = dato;
  ptrAux->sgte = fin();

  return ptrAux;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaCl adicionarPrincipio(listaClubes &lista, DatoCl dato) {

  /* crea el nodo */
  PtrNodoListaCl ptrNuevoNodo = crearNodoLista(dato);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaCl adicionarDespues(listaClubes &lista, DatoCl dato, PtrNodoListaCl ptrNodo) {

  PtrNodoListaCl ptrNuevoNodo = fin();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,dato);

  else {
    if (ptrNodo != fin()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(dato);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaCl adicionarFinal(listaClubes &lista, DatoCl dato) {

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,dato,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoListaCl adicionarAntes(listaClubes &lista, DatoCl dato, PtrNodoListaCl ptrNodo) {

  PtrNodoListaCl ptrNuevoNodo = fin();

  if (! listaVacia(lista)) {
    if (ptrNodo != primero(lista))
      ptrNuevoNodo = adicionarDespues(lista,dato,anterior(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(lista,dato);
   }
   return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
void colocarDato(listaClubes &lista, DatoCl &dato, PtrNodoListaCl ptrNodo) {

  if ( (! listaVacia(lista)) && (ptrNodo != fin()))
     ptrNodo->dato = dato;
}

/*----------------------------------------------------------------------------*/
void obtenerDato(listaClubes &lista, DatoCl &dato, PtrNodoListaCl ptrNodo) {

  if ((! listaVacia(lista)) && (ptrNodo != fin()))
    dato = ptrNodo->dato;
}

/*----------------------------------------------------------------------------*/
void eliminarNodo(listaClubes &lista, PtrNodoListaCl ptrNodo) {

  PtrNodoListaCl ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(lista)) && (ptrNodo != fin())) {

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
void eliminarNodoPrimero(listaClubes &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(listaClubes &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarLista(listaClubes &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoListaCl localizarDato(listaClubes &lista, DatoCl dato) {

   bool encontrado = false;
   DatoCl datoCursor;
   PtrNodoListaCl ptrCursor = primero(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != fin()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerDato(lista,datoCursor,ptrCursor);
    if (compararDato(datoCursor,dato) == IGUAL)
      encontrado = true;
    else
      ptrCursor = siguiente(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = fin();

  return ptrCursor;
}

/*----------------------------------------------------------------------------*/
void eliminarDato(listaClubes &lista, DatoCl dato) {

  /* localiza el dato y luego lo elimina */
  PtrNodoListaCl ptrNodo = localizarDato(lista,dato);
  if (ptrNodo != fin())
    eliminarNodo(lista,ptrNodo);
}

/*----------------------------------------------------------------------------*/
PtrNodoListaCl insertarDato(listaClubes &lista, DatoCl dato) {

  PtrNodoListaCl ptrPrevio = primero(lista);
  PtrNodoListaCl ptrCursor = primero(lista);
  PtrNodoListaCl ptrNuevoNodo;
  DatoCl datoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != fin()) && (! ubicado)) {

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

void reordenar(listaClubes &lista) {

  listaClubes temp = lista;
  PtrNodoListaCl ptrCursor = primero(temp);
  crearLista(lista);
  while ( ptrCursor != fin() ) {
        DatoCl dato;
        obtenerDato( temp, dato, ptrCursor);
        insertarDato( lista, dato );
        eliminarNodo( temp, ptrCursor );
        ptrCursor = primero(temp);
  }
  eliminarLista( temp );
}

/*----------------------------------------------------------------------------*/

int longitud(listaClubes &lista){
  PtrNodoListaCl ptrCursor = primero(lista);
  int longitud = 0;
  while ( ptrCursor != fin() ) {
        longitud++;
        ptrCursor = siguiente( lista, ptrCursor);
  }
  return longitud;
}
