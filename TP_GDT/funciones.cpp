#include "funciones.h"
#include "listaEquipos.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

void cagarEquipos(ListaEquipo &lista){
    char id[2],nombre[30],usuario[30];
    int idEntero;
    ifstream fequipo ("equipos.db",ios::in);
    if(!fequipo) cout << "no existe el arhcivo de equipos";
    while(!fequipo.eof()){
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
