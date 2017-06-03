#include "funciones.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>


using namespace std;


void cargarClubes(listaClubes &lista){
    char id[3];
    char* nom;
    ifstream fclub ("clubes.db",ios::in);
    if(!fclub) cout << "no existe el archivo de clubes";
    while(!fclub.eof() ){
        nom = new char[30];
        Club cl;
        crear(cl);
        fclub.getline(id,3,';');
        setId(cl, atoi(id));
        fclub.getline(nom,30,'\n');
        setNombre(cl, nom);
        adicionarFinal(lista, cl);

    }
    fclub.close();
}

void cargarEquipos(ListaEquipo &lista){
    char id[3];
    char* nombre;
    char* usuario;
    ifstream fequipo ("equipos.db",ios::in);
    if(!fequipo) cout << "no existe el arhcivo de equipos";
    while(!fequipo.eof()){
        nombre= new char[30];
        usuario= new char[30];
        Equipo equipo;
        crear(equipo);
        fequipo.getline(id,3,';');
        setId(equipo, atoi(id));
        fequipo.getline(nombre,30,';');
        setNombre(equipo,nombre);
        fequipo.getline(usuario,30,'\n');
        setNombreUsuario(equipo,usuario);
        adicionarFinalEquipo(lista,equipo);
    }
    fequipo.close();
}

void cargarJugadoresPorEquipo (listaJxE &lista){
    char idE[3],idJ[3];
    ifstream fJugadoresPorEquipo("jugadoresPorEquipo.db",ios::in);
    if(!fJugadoresPorEquipo)cout<<"no existe el arhcivo de jugadores por equipo ";
    while(!fJugadoresPorEquipo.eof()){
        JugadoresPorEquipo JxE;
        crear(JxE);
        fJugadoresPorEquipo.getline(idE,3,';');
        setIdEquipo(JxE,atoi(idE));
        fJugadoresPorEquipo.getline(idJ,3,'\n');
        setIdJugador(JxE,atoi(idJ));
        adicionarFinal(lista, JxE);
    }
}
void MostrarEnPantallaEquipos (ListaEquipo &lista){

    PtrNodoListaEquipo cursor = primeroEquipo(lista);
    DatoEquipo dato;

    while (cursor!= finEquipo()){
        obtenerDatoEquipo(lista, dato, cursor);
        cout << dato.id<<" "<<dato.nombre<<" "<<dato.nombreUsuario <<" "<<dato.puntajeFecha << endl;
        cursor= siguienteEquipo(lista,cursor);
    }
}

void MostrarEnPantallaClubes(listaClubes &lista){
    PtrNodoListaCl cursor = primero(lista);
    Club club;

    while (cursor!= finClub()){
        obtenerDato(lista, club, cursor);
        cout << club.idClub<<" "<<club.nombre<< endl;
        cursor= siguiente(lista,cursor);
    }
}

void MostrarEnPantallaJugadoresPorEquipo(listaJxE &lista){

    PtrNodoListaJxE cursor = primero(lista);
    JugadoresPorEquipo JxE;

    while (cursor!= finJxE()){
        obtenerDato(lista, JxE, cursor);
        cout << JxE.idEquipo<<" "<<JxE.idJugador << endl;
        cursor= siguiente(lista,cursor);
    }
}

void ordenarEquiposPorAtrivuto(ListaEquipo &lista,AtrivutoComparacion atrivuto){
  //  void intercambiarEquipo(PtrNodoListaEquipo cursor);
 PtrNodoListaEquipo cursor=primeroEquipo(lista);
  Equipo equipo;
  int i,j;
  for(i=2;i<=longitudEquipo(lista);i++){
    for(j=1;j<=longitudEquipo(lista)-1;j++){
        //if(getPuntajeFecha(cursor->dato)<getPuntajeFecha(cursor->sgte->dato) ){
        switch(atrivuto){
            case ID:
                if(compararDatoEquipo(cursor->dato,siguienteEquipo(lista,cursor)->dato,ID) == MENOR){
                    equipo=cursor->dato;
                    cursor->dato=cursor->sgte->dato;
                    cursor->sgte->dato=equipo;
                   // intercambiar(cursor);
                }
                break;
            case FECHA:
                if(compararDatoEquipo(cursor->dato,siguienteEquipo(lista,cursor)->dato,FECHA) == MENOR){
                    equipo=cursor->dato;
                    cursor->dato=cursor->sgte->dato;
                    cursor->sgte->dato=equipo;

                   // intercambiar(cursor);
                }
                break;
            case TOTAL:
                if(compararDatoEquipo(cursor->dato,siguienteEquipo(lista,cursor)->dato,TOTAL) == MENOR){
                    equipo=cursor->dato;
                    cursor->dato=cursor->sgte->dato;
                    cursor->sgte->dato=equipo;

                 //   intercambiar(cursor);
                }
                break;
            }
            cursor=siguienteEquipo(lista,cursor);
        }
        cursor=primeroEquipo(lista);
    }
/*
void intercambiarEquipo(cursor){
    Equipo equipo;
    equipo=cursor->dato;
    cursor->dato=cursor->sgte->dato;
    cursor->sgte->dato=equipo;
}
*/
}



