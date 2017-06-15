#include "funciones.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>


using namespace std;

void escribirMenuPrincipal(){
    cout<<"menu"<<endl<<endl<<"1)Procesamiento de archivos"<<endl<<"2)Procesamiento de fechas"<<endl<<"3)Salir"<<endl;
}

void escribirMenuArchivos(){
    cout<<endl<<endl<<"1)Cargar Clubes"<<endl<<"2)Cargar Jugadores"<<endl<<"3)Cargar Equipos"<<endl<<"4)Cargar Jugadores por equipo"<<endl;
}

void escribirError(char* error){
 //no aplicado aun
}

void validaciones(ListaEquipo &listaE){
    char* error;
    int contarARQ=0,contarDEF=0,contarMED=0,contarDEL=0,valorT=0;
    PtrNodoListaEquipo cursorE=primeroEquipo(listaE);
    PtrNodoLista cursorJ;
    DatoEquipo datoE;
    Dato datoJ;
    Configuracion config;
    setConfiguracion(config);
    //cout<<"Prueba del recorrido de lista:"<<endl;
    while(cursorE!=finEquipo()){
        obtenerDatoEquipo(listaE,datoE,cursorE);
        cursorJ=primero(*datoE.jugadores);
        //cout<<"Prueba recorrida Equipo: "<<datoE.nombreUsuario<<endl;
        while(cursorJ!=finJugadores()){
            obtenerDato(*datoE.jugadores,datoJ,cursorJ);
            //cout<<"Prueba recorrida lista jugadores"<<endl;
            //cout<<"Jugador: "<<datoJ.nombre<<endl;
            if(getPosicion(datoJ)==ARQ){
                contarARQ=contarARQ+1;
            }
            if(getPosicion(datoJ)==DEF){
                contarDEF=contarDEF+1;
            }
            if(getPosicion(datoJ)==MED){
                contarMED=contarMED+1;
            }
            if(getPosicion(datoJ)==DEL){
                contarDEL=contarDEL+1;
            }
            valorT=valorT+datoJ.precio;
            cursorJ = siguiente(*getJugadores(datoE),cursorJ);
        }
        if(contarARQ>getARQ(config)){
            strcpy(error,"Cantidad de arqueros disponible superada");
            cout<<"Cantidad de arqueros disponible superada"<<endl;
            cout<<"El equipo "<<getNombre(datoE)<<" sera eliminado"<<endl;
            escribirError(error);
            eliminarNodoEquipo(listaE,cursorE);
        }
        if(contarDEF>getDEF(config)){
            strcpy(error,"Cantidad de defensores disponible superada");
            cout<<"Cantidad de defensores disponible superada"<<endl;
            cout<<"El equipo "<<getNombreUsuario(datoE)<<" sera eliminado"<<endl;
            escribirError(error);
            eliminarNodoEquipo(listaE,cursorE);
        }

        if(contarMED>getMED(config)){
            strcpy(error,"Cantidad de mediocampistas disponible superada");
            cout<<"Cantidad de mediocampistas disponible superada"<<endl;
            cout<<"El equipo "<<getNombreUsuario(datoE)<<" sera eliminado"<<endl;
            escribirError(error);
            eliminarNodoEquipo(listaE,cursorE);
        }

        if(contarDEL>getDEL(config)){
            strcpy(error,"Cantidad de delanteros disponible superada");
            cout<<"Cantidad de delanteros disponible superada"<<endl;
            cout<<"El equipo "<<getNombreUsuario(datoE)<<" sera eliminado"<<endl;
            escribirError(error);
            eliminarNodoEquipo(listaE,cursorE);
        }
        //cout<<"Cantidad de defensores en equipo "<<datoE.nombre<<" "<< contarDEF<<endl;
        //cout<<"Valor total del equipo " <<datoE.nombreUsuario<<" "<< valorT<<endl;
        contarARQ=0;
        contarDEF=0;
        contarMED=0;
        contarDEL=0;
        valorT=0;
        cursorE = siguienteEquipo(listaE,cursorE);
    }

}

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
    fJugadoresPorEquipo.close();
}

void cologarJugadoresEnEquipos(listaJxE &jxe, ListaEquipo &equipos, ListaJugador &jugadores){
    PtrNodoListaJxE cursorJxe= primero(jxe);
    Equipo equipoAux;
    crear(equipoAux);
    Jugador jugadorAux;
    crear(jugadorAux);
    while(cursorJxe!=finJxE()){
        setId(equipoAux,getidEquipo(cursorJxe->dato));
        PtrNodoListaEquipo cursorEquipo= localizarDatoEquipo(equipos,equipoAux);
        setId(jugadorAux,getidJugador(cursorJxe->dato));
        PtrNodoLista cursorJugador = localizarDato(jugadores,jugadorAux);
        adicionarFinal (*getJugadores(cursorEquipo->dato),cursorJugador->dato);
        cursorJxe = siguiente(jxe,cursorJxe);
    }

}

void cargarJugadores(ListaJugador &lista){
    char id[3],idClub[3], posicion[4],precio[10];
    char* nombre;
    Posicion pos=ARQ;
    ifstream fJugador ("jugadores.db",ios::in);
    if(!fJugador) cout<<"no existe el archivo de jugadores";
    while(!fJugador.eof()){
        nombre = new char[30];
        Jugador jugador;
        crear(jugador);
        fJugador.getline(id,3,';');
        setId(jugador, atoi(id));
        fJugador.getline(nombre,30,';');
        setNombre(jugador, nombre);
        fJugador.getline(idClub,3,';');
        setIdClub(jugador, atoi(idClub));
        fJugador.getline(posicion,4,';');
        if(!strcmp(posicion,"ARQ")) pos=ARQ;
        else if(!strcmp(posicion,"DEF"))pos=DEF;
        else if(!strcmp(posicion,"MED"))pos=MED;
        else if(!strcmp(posicion,"DEL"))pos=DEL;
        setPosicion(jugador,pos);
        fJugador.getline(precio,10,'\n');
        setPrecio(jugador,atof(precio));
        adicionarFinal(lista,jugador);
    }
    fJugador.close();
}

void cargarPuntosPorJugador (listaPJ &lista){
    char id[3], fecha[3], puntos[5];
    ifstream fppj ("puntosPorJugador.db",ios::in);
    if(!fppj)cout<<"no existe el archivo de puntos por jugador";
    while(!fppj.eof()){
        puntajesPorJugador puntajeXJ;
        crear(puntajeXJ);
        fppj.getline(id,3,';');
        setIdJugador(puntajeXJ,atoi(id));
        fppj.getline(fecha,3,';');
        setFecha(puntajeXJ,atoi(fecha));
        fppj.getline(puntos,5,'\n');
        setPuntos(puntajeXJ,atoi(puntos));
        adicionarFinal(lista,puntajeXJ);
    }
    fppj.close();
}


void procesarFechas(listaPJ &pj, ListaEquipo &equipos,ListaJugador &jugadores){
    PtrNodoListaPJ cursorPJ= primero(pj);
    PtrNodoLista cursorJ;
    PtrNodoListaEquipo cursorE;
    Equipo equipoAux;
    crear(equipoAux);
    Jugador jugadorAux;
    crear(jugadorAux);
    int fechaAcutal=0;
    int c=0;
    while(cursorPJ != finPJ()){
        fechaAcutal=getFecha(cursorPJ->dato);
        while((cursorPJ!= finPJ()) && (fechaAcutal==getFecha(cursorPJ->dato))){
            setId(jugadorAux, getIdJugador(cursorPJ->dato));
            cursorJ=localizarDato(jugadores,jugadorAux);
            setPuntajeTotal(cursorJ->dato,getPuntajeTotal(cursorJ->dato) + getPuntos(cursorPJ->dato));
            cursorE=primeroEquipo(equipos);
            while(cursorE!=finEquipo()){
                cursorJ=localizarDato(*getJugadores(cursorE->dato),jugadorAux);
                if(cursorJ!=finJugadores()){
                    setPuntajeFecha(cursorE->dato,getPuntajeFecha(cursorE->dato) + getPuntos(cursorPJ->dato));
                    setPuntajeTotal(cursorE->dato,getPuntajeTotal(cursorE->dato) + getPuntos(cursorPJ->dato));
                }
                cursorE= siguienteEquipo(equipos, cursorE);
            }
        cursorPJ= siguiente(pj,cursorPJ);
        }
        ordenarEquiposPorAtrivuto(equipos,FECHA);
        escribirArchivoFecha(equipos,fechaAcutal);
        setearPuntajesFecha(equipos);
    }
    ordenarEquiposPorAtrivuto(equipos,TOTAL);
    escribirArchivoTotalEquipo(equipos);
    ordenarJugadorPorAtrivuto(jugadores,TOTAL);
    escribirArchivoTotalJugador(jugadores);
}

void escribirArchivoFecha(ListaEquipo &equipos, int fechaAcual){
    char principio[15]="archivoFecha ";
    char fin[5]=".txt";
    char fecha[3];
    itoa(fechaAcual,fecha,10);
    char nombreArchivo[22];
    strcat(nombreArchivo,principio);
    strcat(nombreArchivo,fecha);
    strcat(nombreArchivo,fin);
    ofstream ffecha(nombreArchivo,ios::out);
    PtrNodoListaEquipo cursorE = primeroEquipo(equipos);
    int c=1;
    while(cursorE!=finEquipo()){
            ffecha<<c<<" "<<getId(cursorE->dato)<<" "<<getNombre(cursorE->dato)<<" "<<getNombreUsuario(cursorE->dato)<<" "<<getPuntajeFecha(cursorE->dato)<<endl;
            c++;
            cursorE= siguienteEquipo(equipos,cursorE);
    }
    ffecha.close();
}

void escribirArchivoTotalEquipo(ListaEquipo &equipos){
    ofstream ftotalEquipo("puntajesTotalesPorEquipo.txt",ios::out);
    PtrNodoListaEquipo cursorE = primeroEquipo(equipos);
    int c=1;
    while(cursorE!=finEquipo()){
            ftotalEquipo<<c<<" "<<getId(cursorE->dato)<<" "<<getNombre(cursorE->dato)<<" "<<getNombreUsuario(cursorE->dato)<<" "<<getPuntajeTotal(cursorE->dato)<<endl;
            c++;
            cursorE= siguienteEquipo(equipos,cursorE);
    }
    ftotalEquipo.close();
}

void escribirArchivoTotalJugador(ListaJugador &jugadores){
    ofstream ftotalJugador("puntajesTotalesPorJugador.txt",ios::out);
    PtrNodoLista cursorJ = primero(jugadores);
    int c=1;
    while(cursorJ!=finJugadores()){
            ftotalJugador<<c<<" "<<getId(cursorJ->dato)<<" "<<getPuntajeTotal(cursorJ->dato)<<endl;
            c++;
            cursorJ= siguiente(jugadores,cursorJ);
    }
    ftotalJugador.close();
}

void setearPuntajesFecha(ListaEquipo &equipos){
    PtrNodoListaEquipo cursorE= primeroEquipo(equipos);
    while(cursorE!=finEquipo()){
        setPuntajeFecha(cursorE->dato,0);
        cursorE=siguienteEquipo(equipos,cursorE);
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

void MostrarEnPantallaEquiposConJugadores (ListaEquipo &lista){

    PtrNodoListaEquipo cursor = primeroEquipo(lista);
    DatoEquipo dato;
    Jugador jug;

    while (cursor!= finEquipo()){
        obtenerDatoEquipo(lista, dato, cursor);
        cout << dato.id<<" "<<dato.nombre<<" "<<dato.nombreUsuario <<" "<<dato.puntajeFecha << endl;
        PtrNodoLista cursorJugador= primero(*getJugadores(cursor->dato));
        while(cursorJugador!=finJugadores()){
                obtenerDato(*getJugadores(cursor->dato),jug,cursorJugador);
                cout  <<"    "<<getNombre(jug)<< endl;
                cursorJugador=siguiente(*getJugadores(cursor->dato),cursorJugador);
        }
        cursor= siguienteEquipo(lista,cursor);
    }
}

void MostrarEnPantallaJugadores(ListaJugador &lista){
    PtrNodoLista cursor = primero(lista);
    Jugador jug;

    while(cursor!= finJugadores()){
        obtenerDato(lista, jug, cursor);
        cout<<jug.id<<" "<<jug.nombre<<" "<<jug.idClub<<" "<<jug.posision<<" "<<jug.precio<<endl;
        cursor= siguiente(lista,cursor);
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

void MostrarEnPantallaPuntosPorJugador (listaPJ &lista){

    PtrNodoListaPJ cursor = primero(lista);
    puntajesPorJugador pxj;

    while (cursor!= finPJ()){
        obtenerDato(lista, pxj, cursor);
        cout << pxj.idJugador<<" "<<pxj.fecha <<" "<<pxj.puntos << endl;
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

void ordenarJugadorPorAtrivuto(ListaJugador &lista, AtrivutoComparacion atrivuto){
 PtrNodoLista cursor=primero(lista);
  Jugador jugador;
  int i,j;
  for(i=2;i<=longitud(lista);i++){
    for(j=1;j<=longitud(lista)-1;j++){
        switch(atrivuto){
            case ID:
                if(compararDato(cursor->dato,siguiente(lista,cursor)->dato,ID) == MENOR){
                    jugador=cursor->dato;
                    cursor->dato=cursor->sgte->dato;
                    cursor->sgte->dato=jugador;
                }
                break;
            case FECHA:
                if(compararDato(cursor->dato,siguiente(lista,cursor)->dato,FECHA) == MENOR){
                    jugador=cursor->dato;
                    cursor->dato=cursor->sgte->dato;
                    cursor->sgte->dato=jugador;
                }
                break;
            case TOTAL:
                if(compararDato(cursor->dato,siguiente(lista,cursor)->dato,TOTAL) == MENOR){
                    jugador=cursor->dato;
                    cursor->dato=cursor->sgte->dato;
                    cursor->sgte->dato=jugador;
                }
                break;
            }
            cursor=siguiente(lista,cursor);
        }
        cursor=primero(lista);
    }

}


