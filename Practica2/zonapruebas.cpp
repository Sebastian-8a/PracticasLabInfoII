#include "zonapruebas.h"

int caminosPosibles(int n){
    int combinacion  = 0;
    combinacion = (factorial(n*2))/(factorial(n)*factorial(n));
    return combinacion;
}
