#include <iostream>

void fun_c(double *a, int n, double *promedio, double*suma);

int main(int argc, char *argv[])
{




    return 0;
}

void fun_c(double *a, int n, double *promedio, double *suma){
    int i;
    suma = 0.0;
    for (i = 0; i < n; i++)
        suma += (a + i);
    promedio = suma / n;
}
