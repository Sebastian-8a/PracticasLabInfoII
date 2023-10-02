
#include "zonapruebas.h"
#include "funciones.h"


int main(){
    int bloque = 0, numBloques = 0, len = 0;
    string contenido = "", bin = "";
    cout << "Ingrese el tamaño del bloque: ";
    cin >> bloque;
    contenido = leer("archivo1.txt");
    bin = contenidoEnBinario(contenido);        //generar un try en caso de que el número de bloque ingresado no sea multiplo del total de elementos
    len = bin.length();
    numBloques = len / bloque;
    for (int i = 0; i < numBloques; i++ ){

    }



    return 0;
}
