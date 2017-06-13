#include "listaEquipos.h"
#include "listaClubes.h"
#include "listaJugadoresPorEquipo.h"
#include "listaJugadores.h"
#include "listaPuntajesPorJugador.h"
#include <stdio.h>

#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

void cargarClubes(listaClubes &lista);

void cargarEquipos(ListaEquipo &lista);

void cargarJugadoresPorEquipo (listaJxE &lista);

void cargarJugadores(ListaJugador &lista);

void cologarJugadoresEnEquipos(listaJxE &jxe, ListaEquipo &equipos, ListaJugador &jugadores);

void MostrarEnPantallaEquipos (ListaEquipo &lista);

void MostrarEnPantallaEquiposConJugadores (ListaEquipo &lista);

void MostrarEnPantallaJugadores(ListaJugador &lista);

void MostrarEnPantallaClubes(listaClubes &lista);

void MostrarEnPantallaJugadoresPorEquipo(listaJxE &lista);

void ordenarEquiposPorAtrivuto(ListaEquipo &lista, AtrivutoComparacion atrivuto);

void intercambiarEquipo(PtrNodoListaEquipo cursor);

#endif // __FUNCIONES_H__
