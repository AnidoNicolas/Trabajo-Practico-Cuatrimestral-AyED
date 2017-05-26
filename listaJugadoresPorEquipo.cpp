#include "listaJugadoresPorEquipo.h"

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
/* Implementación de Primitivas */ResultadoComparacion compararDato(DatoPJ dato1, DatoPJ dato2) {
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
  lista.primero = finJxE();
}

/*----------------------------------------------------------------------------*/
bool listaVacia(listaPJ &lista) {

  return (primero(lista) == finJxE());
}

PtrNodoListaPxE finJxE() {
  return NULL;
}

/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
PtrNodoListaPxE primero(listaPJ &lista) {
  return lista.primero;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE siguiente(listaPJ&lista, PtrNodoListaPxE ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVacia(lista)) && (ptrNodo != finJxE()))
    return ptrNodo->sgte;
  else
    return finJxE();
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE anterior(listaPJ &lista, PtrNodoListaPxE ptrNodo) {

  PtrNodoListaPxE ptrPrevio = finJxE();
  PtrNodoListaPxE ptrCursor = primero(lista);

  while (( ptrCursor != finJxE()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE ultimo(listaPJ &lista) {

  /* el último nodo de la lista es el anterior al fin() */
  return anterior(lista,finJxE());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE crearNodoLista(DatoPJ dato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoListaPxE ptrAux = new NodoListaPJ;

  ptrAux->dato = dato;
  ptrAux->sgte = finJxE();

  return ptrAux;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE adicionarPrincipio(listaPJ &lista, DatoPJ dato) {

  /* crea el nodo */
  PtrNodoListaPxE ptrNuevoNodo = crearNodoLista(dato);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE adicionarDespues(listaPJ &lista, DatoPJ dato, PtrNodoListaPxE ptrNodo) {

  PtrNodoListaPxE ptrNuevoNodo = finJxE();

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
PtrNodoListaPxE adicionarFinal(listaPJ &lista, DatoPJ dato) {

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,dato,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE adicionarAntes(listaPJ &lista, DatoPJ dato, PtrNodoListaPxE ptrNodo) {

  PtrNodoListaPxE ptrNuevoNodo = finJxE();

  if (! listaVacia(lista)) {
    if (ptrNodo != primero(lista))
      ptrNuevoNodo = adicionarDespues(lista,dato,anterior(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(lista,dato);
   }
   return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
void colocarDato(listaPJ &lista, DatoPJ &dato, PtrNodoListaPxE ptrNodo) {

  if ( (! listaVacia(lista)) && (ptrNodo != finJxE()))
     ptrNodo->dato = dato;
}

/*----------------------------------------------------------------------------*/
void obtenerDato(listaPJ &lista, DatoPJ &dato, PtrNodoListaPxE ptrNodo) {

  if ((! listaVacia(lista)) && (ptrNodo != finJxE()))
    dato = ptrNodo->dato;
}

/*----------------------------------------------------------------------------*/
void eliminarNodo(listaPJ &lista, PtrNodoListaPxE ptrNodo) {

  PtrNodoListaPxE ptrPrevio;

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
PtrNodoListaPxE localizarDato(listaPJ &lista, DatoPJ dato) {

   bool encontrado = false;
   DatoPJ datoCursor;
   PtrNodoListaPxE ptrCursor = primero(lista);

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
void eliminarDato(listaPJ &lista, DatoPJ dato) {

  /* localiza el dato y luego lo elimina */
  PtrNodoListaPxE ptrNodo = localizarDato(lista,dato);
  if (ptrNodo != finJxE())
    eliminarNodo(lista,ptrNodo);
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE insertarDato(listaPJ &lista, DatoPJ dato) {

  PtrNodoListaPxE ptrPrevio = primero(lista);
  PtrNodoListaPxE ptrCursor = primero(lista);
  PtrNodoListaPxE ptrNuevoNodo;
  DatoPJ datoCursor;
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

void reordenar(listaPJ &lista) {

  listaPJ temp = lista;
  PtrNodoListaPxE ptrCursor = primero(temp);
  crearLista(lista);
  while ( ptrCursor != finJxE() ) {
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
  PtrNodoListaPxE ptrCursor = primero(lista);
  int longitud = 0;
  while ( ptrCursor != finJxE() ) {
        longitud++;
        ptrCursor = siguiente( lista, ptrCursor);
  }
  return longitud;
}
/*------------------------------*/

PtrNodoListaPxE finPxE() {
void crearLista(listaJxE &lista) {
  lista.primero = finJxE();
}

/*----------------------------------------------------------------------------*/
bool listaVacia(listaJxE &lista) {

  return (primero(lista) == finJxE());
}

PtrNodoListaPxE finJxE() {
  return NULL;
}

/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
PtrNodoListaPxE primero(listaJxE &lista) {
  return lista.primero;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE siguiente(listaJxE&lista, PtrNodoListaPxE ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVacia(lista)) && (ptrNodo != finJxE()))
    return ptrNodo->sgte;
  else
    return finJxE();
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE anterior(listaJxE &lista, PtrNodoListaPxE ptrNodo) {

  PtrNodoListaPxE ptrPrevio = finJxE();
  PtrNodoListaPxE ptrCursor = primero(lista);

  while (( ptrCursor != finJxE()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE ultimo(listaJxE &lista) {

  /* el último nodo de la lista es el anterior al fin() */
  return anterior(lista,finJxE());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE crearNodoLista(DatoPJ dato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoListaPxE ptrAux = new NodoListaPJ;

  ptrAux->dato = dato;
  ptrAux->sgte = finJxE();

  return ptrAux;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE adicionarPrincipio(listaJxE &lista, DatoPJ dato) {

  /* crea el nodo */
  PtrNodoListaPxE ptrNuevoNodo = crearNodoLista(dato);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE adicionarDespues(listaJxE &lista, DatoPJ dato, PtrNodoListaPxE ptrNodo) {

  PtrNodoListaPxE ptrNuevoNodo = finJxE();

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
PtrNodoListaPxE adicionarFinal(listaJxE &lista, DatoPJ dato) {

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,dato,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE adicionarAntes(listaJxE &lista, DatoPJ dato, PtrNodoListaPxE ptrNodo) {

  PtrNodoListaPxE ptrNuevoNodo = finJxE();

  if (! listaVacia(lista)) {
    if (ptrNodo != primero(lista))
      ptrNuevoNodo = adicionarDespues(lista,dato,anterior(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(lista,dato);
   }
   return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
void colocarDato(listaJxE &lista, DatoPJ &dato, PtrNodoListaPxE ptrNodo) {

  if ( (! listaVacia(lista)) && (ptrNodo != finJxE()))
     ptrNodo->dato = dato;
}

/*----------------------------------------------------------------------------*/
void obtenerDato(listaJxE &lista, DatoPJ &dato, PtrNodoListaPxE ptrNodo) {

  if ((! listaVacia(lista)) && (ptrNodo != finJxE()))
    dato = ptrNodo->dato;
}

/*----------------------------------------------------------------------------*/
void eliminarNodo(listaJxE &lista, PtrNodoListaPxE ptrNodo) {

  PtrNodoListaPxE ptrPrevio;

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
PtrNodoListaPxE localizarDato(listaJxE &lista, DatoPJ dato) {

   bool encontrado = false;
   DatoPJ datoCursor;
   PtrNodoListaPxE ptrCursor = primero(lista);

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
void eliminarDato(listaJxE &lista, DatoPJ dato) {

  /* localiza el dato y luego lo elimina */
  PtrNodoListaPxE ptrNodo = localizarDato(lista,dato);
  if (ptrNodo != finJxE())
    eliminarNodo(lista,ptrNodo);
}

/*----------------------------------------------------------------------------*/
PtrNodoListaPxE insertarDato(listaJxE &lista, DatoPJ dato) {

  PtrNodoListaPxE ptrPrevio = primero(lista);
  PtrNodoListaPxE ptrCursor = primero(lista);
  PtrNodoListaPxE ptrNuevoNodo;
  DatoPJ datoCursor;
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
  PtrNodoListaPxE ptrCursor = primero(temp);
  crearLista(lista);
  while ( ptrCursor != finJxE() ) {
        DatoPJ dato;
        obtenerDato( temp, dato, ptrCursor);
        insertarDato( lista, dato );
        eliminarNodo( temp, ptrCursor );
        ptrCursor = primero(temp);
  }
  eliminarLista( temp );
}

/*----------------------------------------------------------------------------*/

int longitud(listaJxE &lista){
  PtrNodoListaPxE ptrCursor = primero(lista);
  int longitud = 0;
  while ( ptrCursor != finJxE() ) {
        longitud++;
        ptrCursor = siguiente( lista, ptrCursor);
  }
  return longitud;
}
