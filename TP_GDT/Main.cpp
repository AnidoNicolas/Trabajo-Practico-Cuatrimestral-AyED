#include "funciones.h"
#include "configuracion.h"
#include "listaClubes.h"
#include "listaJugadores.h"
#include "listaEquipos.h"
#include "listaPuntajesPorJugador.h"


#include <iostream>

using namespace std;


int main(){


listaClubes clubes;
crearLista(clubes);
ListaJugador jugadores;
crearLista(jugadores);
ListaEquipo equipos;
crearListaEquipo(equipos);
listaJxE jxe;
crearLista(jxe);

listaPJ pxj;
crearLista(pxj);

int opcion,opcion2=0,bandera=0, b1=0,b2=0,b3=0,b4=0;
while(bandera==0){
    system("cls");
    escribirMenuPrincipal();
    cin>>opcion;
    switch(opcion){
    case 1:


        Configuracion config;
        crear(config);
        setConfiguracion(config);
        while(b1==0||b2==0||b3==0||b4==0){
            system("cls");
            escribirMenuArchivos();
            cin>>opcion2;
            switch(opcion2){
                case 1:
                cargarClubes(clubes);
                //MostrarEnPantallaClubes(clubes);
                //cout<<endl;
                system("cls");
                b1=1;
                cout<<endl<<"Clubes cargados";
                getchar();
                break;
            case 2:
                cargarJugadores(jugadores);
                //MostrarEnPantallaJugadores(jugadores);
                //cout<<endl;
                system("cls");
                b2=1;
                cout<<endl<<"Jugadores cargados";
                getchar();
                break;
            case 3:
                cargarEquipos(equipos);
                //MostrarEnPantallaEquipos(equipos);
                //cout<<endl;
                system("cls");
                b3=1;
                cout<<endl<<"Equipos cargados";
                getchar();
                break;
            case 4:
                cargarJugadoresPorEquipo(jxe);
                //MostrarEnPantallaJugadoresPorEquipo(jxe);
                //cout<<endl;
                system("cls");
                b4=1;
                cout<<endl<<"Jugadores por equipo cargados";
                getchar();
                break;
            default:
                system("cls");
                cout<<endl<<"Opcion incorrecta ";
                getchar();
        }

        }
    break;
    case 2:
        system("cls");

        cargarPuntosPorJugador(pxj);
        //MostrarEnPantallaPuntosPorJugador(pxj);
        //cout<<endl;

        cologarJugadoresEnEquipos(jxe,equipos,jugadores);
        //MostrarEnPantallaEquiposConJugadores(equipos);
        //cout<<endl;

        procesarFechas(pxj,equipos,jugadores);
        cout<<"fechas procesadas!!";
        getchar();
        break;
    case 3:
        bandera=1;
        break;
    default:
        cout<<endl<<"Opcion incorrecta";
        getchar();
        system("cls");
    }
}
}
