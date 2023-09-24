#include "funciones.h"
#include <string>



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
    num = std::stoi(cadena);
    return num;
}

string minusAMayus(string palabra){
    int len =0;
    len = palabra.length();
    for (int i = 0; i < len; i ++){
        palabra[i] = toupper(palabra[i]);
    }
    return palabra;
}

string texto(string ingresado, int *numeros){
    string letras = "", numTemp = "";
    int len  = ingresado.length();
    for (int i = 0; i< len; i++){
        if (isdigit(ingresado[i])){
            numTemp += ingresado[i];
        }
        else{
            letras +=  ingresado[i];
        }
    }
    *numeros = std::stoi(numTemp);
    return letras;
}

int romanoArabigo(string letras){
    map <char, int> mapa;
    mapa['M'] = 1000;
    mapa['D'] = 500;
    mapa['C'] = 100;
    mapa['L'] = 50;
    mapa['X'] = 10;
    mapa['V'] = 5;
    mapa['I'] = 1;

    int  len = 0, suma = 0;
    len = letras.length();
    for(int i = 0 ; i< len; i++){
        if (mapa[letras[i]] < mapa[letras[i+1]]){
            suma += mapa[letras[i+1]] - mapa[letras[i]];
            i++;
        }
        else
            suma += mapa[letras[i]];
    }
    return suma;
}


bool cuadradoMagico(int **matriz, int n){            //modifico el 3 con base en el tamaño de la matriz
    int constante = 0, suma = 0, columna2 = n-1;
    for (int columna = 0; columna < n ; columna ++){
        constante += matriz[0][columna];
    }
    for (int fila = 1; fila<n ; fila++){            // suma de cada fila
        suma = 0;
        for (int columna = 0; columna < n; columna++ ){
            suma += matriz[fila][columna];
        }
        if (suma != constante) return false;
    }
    for (int columna = 0; columna<n ; columna++){           //suma de cada columna
        suma = 0;
        for (int  fila= 0; fila < n; fila++ ){
            suma += matriz[fila][columna];
        }
        if (suma != constante) return false;
    }
    suma = 0;
    for (int i = 0; i<n ; i ++){            //suma de diagonal ppal
        suma += matriz[i][i];
    }
    if (suma != constante) return false;
    suma = 0;
    for (int i = 0; i < n ; i ++){            //suma de diagonal ppal inversa
        suma += matriz[i][columna2];
        columna2--;
    }
    if (suma != constante) return false;
    return true;
}
