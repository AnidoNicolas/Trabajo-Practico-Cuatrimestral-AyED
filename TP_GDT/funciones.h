#include "listaEquipos.h"
#include "listaClubes.h"

#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

void cargarClubes(listaClubes &lista);

void cargarEquipos(ListaEquipo &lista);

void recorrerEquipo (ListaEquipo &lista);

void recorrerClubes(listaClubes &lista);

void ordenarEquiposPorAtrivuto(ListaEquipo &lista, AtrivutoComparacion atrivuto);

void intercambiarEquipo(PtrNodoListaEquipo cursor);

#endif // __FUNCIONES_H__
