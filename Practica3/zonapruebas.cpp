#include "zonapruebas.h"

int  decimalBinario(int entero){
    int i = 0, binario = 0, producto = 1;
    short int arreglo[8] = {};
    while (entero != 1){
    if ((entero%2) == 1){
        arreglo[7-i] = 1;
        entero = (entero - 1) /2;
        }
    else{
        arreglo[7-i] = 0;
        entero /= 2;
    }
        i ++;
    }
    arreglo[7-i] = 1;


    for (int i = 0; i<8; i++){
        binario += arreglo[7-i] * producto;
        producto *= 10;
    }

    return binario;
}
