#include "zonapruebas.h"


string bloqueCodif(int cantUnos, int cantCeros, string bloqueTemp1){
    string bloqueCodificado;
    int bloque = bloqueTemp1.length();
    if (cantCeros > cantUnos){
        for (int i = 0; i< bloque; i++){
            if ((i % 2) == 0){
                bloqueCodificado += bloqueTemp1[i];
            }
            else
                bloqueCodificado += bloqueTemp1[i] == '1' ? '0' : '1';       //Invertir el valor usando operador ternario
        }
    }
    else if(cantCeros < cantUnos){
        for (int i = 0, j = 1; i < bloque; i++){
            if (j == 3){                //3 para modificar cada que se pasen 2 posiciones y se ubique en la tercera
                bloqueCodificado += bloqueTemp1[i] == '1' ? '0' : '1';
                j = 1;
            }
            else{
                bloqueCodificado += bloqueTemp1[i];
                j++;
            }
        }
    }
    else{
        for (int i = 0; i< bloque; i++){
            bloqueCodificado += bloqueTemp1[i] == '1' ? '0' : '1';
        }
    }
    return bloqueCodificado;
}
