#include "listaEquipos.h"
#include "listaClubes.h"
#include "listaJugadoresPorEquipo.h"
#include "listaJugadores.h"
#include "listaPuntajesPorJugador.h"
#include "configuracion.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__
/*
pre: Ninguna
post: Escribe en pantalla el menu principal
*/
void escribirMenuPrincipal();
/*
pre: Ninguna
post: Ecrbribe en pantalla el menu de la carga de archivos
*/
void escribirMenuArchivos();
/*
pre:
post:
*/
void validaciones(ListaEquipo &listaE);
/*
pre:Se debe haber creado la lista de equipos con la carga de sus respectivos jugadores ya realizada, y no debe haber sido eliminada.
post: Validacion de los equipos que cumplen con las condiciones establecidas en el archivo de configuracion.db
*/
void escribirError(char* error);
/*
pre: Se de haber creado la lista de clubes
post: carga los clubes del archvo clubes.db
lista; lista de clubes sobre la cual se aplica la primitiva
*/
void cargarClubes(listaClubes &lista);
/*
pre: Se debe haber creado la lista de equipos
post: carga los equipos del archivo equipos.db
lista: lista de equipos sobre la cual se aplica la primitiva
*/
void cargarEquipos(ListaEquipo &lista);
/*
pre: Se debe haber creado la lista de jugadores por equipo
post: carga los jugadores por equipos del archivo jugadoresPorEquipo.db
lista: lista de jugadores por equipo sobre la cual se aplica la primitiva
*/
void cargarJugadoresPorEquipo (listaJxE &lista);
/*
pre: Se debe haber creado la lista de jugadores
post: carga los jugadores del archivo jugadores.db
lista: lista de jugadores sobre la cual se aplica la primitiva
*/
void cargarJugadores(ListaJugador &lista);
/*
pre: Se debe haber creado la lista de Puntos por jugador
post: carga los puntos por jugador del archivo puntosPorJugador.db
lista: lista de puntos por jugador sobre la cual se aplica la primitiva
*/
void cargarPuntosPorJugador (listaPJ &lista);
/*
pre: se deben haber creado la lista de jugadores por equipo, de equipos y de jugadores
post: agrega los jugadores a los equipos
listaJxE: lista de jugadores por equipo sobre la cual se aplica la primitiva
equipos: lista de equipos sobre la cual se aplica la primitiva
jugadores: lista de jugadores sobre la cual se aplica la primitiva
*/
void cologarJugadoresEnEquipos(listaJxE &jxe, ListaEquipo &equipos, ListaJugador &jugadores);
/*
pre: se deben haber creado y cargado las listas de puntos por jugador equipos y jugadores
post: procesa el archivo de puntos por fecha y emite un archivo por cada fecha con el ranking
      de equipos con mas puntos, un arhivo con el rankin de los equipos con mas puntos en total
      y un archivo con el rankin con mas puntos por jugador
pj: lista de puntos por jugador sobre la cual se aplica la primitiva
equipos: lista de equipos sobre la cual se aplica la primitiva
jugadores: lista de jugadores sobre la cual se aplica la primitiva
*/
void procesarFechas(listaPJ &pj, ListaEquipo &equipos,ListaJugador &jugadores);
/*
pre: se debe haber creado y cargado la lista de equipos
post: Escribe un archivo por cada fecha con el rankin de los equipos con mas puntos
*/
void escribirArchivoFecha(ListaEquipo &equipos, int fechaAcual);
/*
pre: se debe haber creado y cargado la lista de equipos
post: Escribe un archivo con el rankin de los equipos con mas puntos en total
equipos: lista de equipos sobre la cual se aplica la primitiva
*/
void escribirArchivoTotalEquipo(ListaEquipo &equipos);
/*
pre: se debe haber creado y cargado la lista de jugadores
post: Escribe un archivo con el rankin de los jugadores con mas puntos en total
jugadores: lista de jugadores sobre la cual se aplica la primitiva
*/
void escribirArchivoTotalJugador(ListaJugador &jugadores);
/*
pre: se debe haber creado y cargado la lista de equipos
post: setea a 0 todos los puntos de fecha de los equipos
equipos: lista de equipos sobre la cual se aplica la primitiva
*/
void setearPuntajesFecha(ListaEquipo &equipos);
/*
pre: se debe haber creado y cargado la lista de equipos
post: muestra en pantalla los equipos
lista: lista de equipos sobre la cual se aplica la primitiva
*/
void MostrarEnPantallaEquipos (ListaEquipo &lista);
/*
pre: se debe haber creado y cargado la lista de equipos y de jugadores y
     haber colocado los jugadores en los equipos
post: muestra en pantalla los equipos con los jugadores
lista: lista de equipos sobre la cual se aplica la primitiva
*/
void MostrarEnPantallaEquiposConJugadores (ListaEquipo &lista);
/*
pre: se debe haber creado y cargado la lista de jugadores
post: muestra en pantalla los jugadores
lista: lista de jugadores sobre la cual se aplica la primitiva
*/
void MostrarEnPantallaJugadores(ListaJugador &lista);
/*
pre: se debe haber creado y cargado la lista de clubes
post: muestra en pantalla los clubes
lista: lista de clubes sobre la cual se aplica la primitiva
*/
void MostrarEnPantallaClubes(listaClubes &lista);
/*
pre: se debe haber creado y cargado la lista de puntos por jugador
post: muestra en pantalla los jugadores
lista: lista de jugadores sobre la cual se aplica la primitiva
*/
void MostrarEnPantallaPuntosPorJugador (listaPJ &lista);
/*
pre: se debe haber creado y cargado la lista de jugadores por equipo
post: muestra en pantalla los jugadores por equipo
lista: lista de jugadores por equipo sobre la cual se aplica la primitiva
*/
void MostrarEnPantallaJugadoresPorEquipo(listaJxE &lista);
/*
pre: se debe haber creado y cargado la lista de equipos
post: ordena la lista de equipos segun el atrivuto
      ID,FECHA o TOTAL
lista: lista de equipos sobre la cual se aplica la primitiva
atrivuto: atrivuto por el cual se ordena la lista (ID,FECHA o TOTAL)
*/
void ordenarEquiposPorAtrivuto(ListaEquipo &lista, AtrivutoComparacion atrivuto);
/*
pre: se debe haber creado y cargado la lista de jugadores
post: ordena la lista de equipos segun el atrivuto
      ID,FECHA o TOTAL
lista: lista de jugadores sobre la cual se aplica la primitiva
atrivuto: atrivuto por el cual se ordena la lista (ID,FECHA o TOTAL)
*/
void ordenarJugadorPorAtrivuto(ListaJugador &lista,AtrivutoComparacion atrivuto);
/*
pre:
post:
*/
void intercambiarEquipo(PtrNodoListaEquipo cursor);

#endif // __FUNCIONES_H__
