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
        cout << dato.id<<" "<<dato.nombre<<" "<<dato.nombreUsuario << endl;
        cursor= siguienteEquipo(lista,cursor);
    }
}


