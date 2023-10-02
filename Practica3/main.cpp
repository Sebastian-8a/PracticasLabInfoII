
#include "zonapruebas.h"
#include "funciones.h"


int main(){

    string contenido = "", prueba = "";
    contenido = leer("archivo1.txt");
    prueba = contenidoEnBinario(contenido);
    cout <<endl<< prueba;



    return 0;
}
