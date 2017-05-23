#include "configuracion.h"
#include <iostream>

using namespace std;

int main(){
Configuracion config;

crear(config);
setConfiguracion(config);
// verifico q se setearon los valores mostrandolos por pantalla
//cout << getValorMaximoXEquipo(config)<<endl<<getARQ(config)<<endl<<getDEF(config)<<endl<<getMED(config)<<endl<<getDEL(config)<<endl;

}
