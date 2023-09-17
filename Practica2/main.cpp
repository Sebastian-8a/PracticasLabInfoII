#include "zonapruebas.h"
#include "funciones.h"

int main()
{
    double prom = 0.0, sum = 0.0;
    double *promedio = &prom, *suma = &sum;
    double arreglo[5] = {5,4,3,2,1};


    fun_c(arreglo,5,promedio,suma);
    cout << *promedio<< endl << *suma<< endl<< prom << endl<< sum;


    return 0;
}
