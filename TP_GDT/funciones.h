#include "listaEquipos.h"
#include "listaClubes.h"
#include "listaJugadoresPorEquipo.h"

#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

void cargarClubes(listaClubes &lista);

void cargarEquipos(ListaEquipo &lista);

void cargarJugadoresPorEquipo (listaJxE &lista);

void cargarJugadores(ListaJugador &lista);

void MostrarEnPantallaEquipos (ListaEquipo &lista);

void MostrarEnPantallaJugadores(ListaJugador &lista);

void MostrarEnPantallaClubes(listaClubes &lista);

void MostrarEnPantallaJugadoresPorEquipo(listaJxE &lista);

void ordenarEquiposPorAtrivuto(ListaEquipo &lista, AtrivutoComparacion atrivuto);

void intercambiarEquipo(PtrNodoListaEquipo cursor);

#endif // __FUNCIONES_H__
