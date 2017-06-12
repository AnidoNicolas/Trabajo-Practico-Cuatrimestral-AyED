#include "funciones.h"
#include "configuracion.h"
#include "listaClubes.h"
#include "listaJugadores.h"
#include "listaEquipos.h"
#include "listaPuntajesPorJugador.h"


#include <iostream>

using namespace std;

int main(){
Configuracion config;

crear(config);
setConfiguracion(config);
// verifico q se setearon los valores mostrandolos por pantalla
//cout << getValorMaximoXEquipo(config)<<endl<<getARQ(config)<<endl<<getDEF(config)<<endl<<getMED(config)<<endl<<getDEL(config)<<endl
ListaEquipo equipos;
crearListaEquipo(equipos);
cargarEquipos(equipos);
MostrarEnPantallaEquipos(equipos);
cout<<endl;
listaClubes clubes;
crearLista(clubes);
cargarClubes(clubes);
MostrarEnPantallaClubes(clubes);
cout<<endl;
ListaJugador jugadores;
crearLista(jugadores);
cargarJugadores(jugadores);
MostrarEnPantallaJugadores(jugadores);
cout<<endl;
listaJxE jxe;
crearLista(jxe);
cargarJugadoresPorEquipo(jxe);
MostrarEnPantallaJugadoresPorEquipo(jxe);
cout<<endl;
setPuntajeFecha(equipos.primeroEquipo->dato,5);
setPuntajeFecha(equipos.primeroEquipo->sgte->dato,10);
setPuntajeFecha(equipos.primeroEquipo->sgte->sgte->dato,15);
ordenarEquiposPorAtrivuto(equipos,FECHA);
MostrarEnPantallaEquipos(equipos);



Jugador pepe;
crear(pepe);
char nomb[5]="pepe";
setNombre(pepe,nomb);

//adicionarFinal(losPirulos.jugadores,pepe);

//cout << equipos.primeroEquipo->dato.id<<" " << getNombre(losPirulos)<<" " << getNombreUsuario(losPirulos)<<" "<<getJugadores(losPirulos).primero->dato.nombre;


}

