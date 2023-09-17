#include "funciones.h"

void Funciones()
{

}

void fun_c(double *a, int n, double *promedio, double*suma){
    int i = 0;
    *suma = 0.0;
    for (i ; i < n; i++)
        *suma += (a[i]);
    *promedio = *suma / n;
}
