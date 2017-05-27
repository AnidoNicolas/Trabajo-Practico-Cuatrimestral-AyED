#include "funciones.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>


using namespace std;

void cargarEquipos(ListaEquipo &lista){
    char id[2];
    char* nombre;
    char* usuario;
    int idEntero;
    ifstream fequipo ("equipos.db",ios::in);
    if(!fequipo) cout << "no existe el arhcivo de equipos";
    while(!fequipo.eof()){
        nombre= new char[30];
        usuario= new char[30];
        Equipo equipo;
        crear(equipo);
        fequipo.getline(id,2,';');
        setId(equipo, atoi(id));
        fequipo.getline(nombre,30,';');
        setNombre(equipo,nombre);
        fequipo.getline(usuario,30,'\n');
        setNombreUsuario(equipo,usuario);
        adicionarFinalEquipo(lista,equipo);

    }
}
void recorrerEquipo (ListaEquipo &lista){

    PtrNodoListaEquipo cursor = primeroEquipo(lista);
    DatoEquipo dato;

    while (cursor!= finEquipo()){
        obtenerDatoEquipo(lista, dato, cursor);
        cout << dato.id<<" "<<dato.nombre<<" "<<dato.nombreUsuario <<" "<<dato.puntajeFecha << endl;
        cursor= siguienteEquipo(lista,cursor);
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



