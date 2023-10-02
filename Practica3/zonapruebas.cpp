#include "zonapruebas.h"

string contenidoEnBinario(string contenido){
    short int len = contenido.length();
    int temp = 0;
    string binario = "";
    for (int i = 0; i < len; i++){
        temp = decimalBinario(contenido[i]);
        binario+= to_string(temp);
    }
    return binario;
}
