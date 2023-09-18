#include "funciones.h"

void Funciones()
{

}



void fun_c(double *a, int n, double *promedio, double *suma){
    int i = 0;
    * suma = 0.0;
    for (i ; i < n; i++)
        *suma += (a[i]);
    *promedio = *suma / n;
}

void aleatorio(char arreglo[], int n){
    char letra;
    for (int i = 0; i < n ;  i++){
        letra = 'A' + rand() % 26;
        arreglo[i] = letra;
    }
}

void contar(char arreglo[], int n, int letras[] ){
    char letra = 'A';
    int suma = 0;
    for(int i = 0; i < 26; i++){
        letra = 'A'+i;
        suma = 0;
        for (int j = 0; j < n; j++){
            if (arreglo[j] == letra) suma += 1;
        }
        letras[i] = suma;
    }
}

int conversionCharInt(string cadena){
    int num = 0;
    num = stoi(cadena);
    return num;
}
