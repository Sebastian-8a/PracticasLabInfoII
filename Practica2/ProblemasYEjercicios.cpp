#include "funciones.h"
//#include <string.h>
void ejercicio2(){
    double prom = 0.0, sum = 0.0;
    double *promedio = &prom, *suma = &sum;
    double arreglo[5] = {5,4,3,2,1};        //Ingresar datos que desee calcular aquí


    fun_c(arreglo,5,promedio,suma);
    cout << "El promedio de los números:";
        for (int k = 0; k < 5; k++) cout << " " << arreglo[k];
    cout << " es: " << prom;
    //*promedio<< endl << *suma<< endl<< prom << endl<< sum;

}



void problema2(){
    char arreglo[200]={};
    int letras[26]={};
    char letra = '@';       //es el caracter que se encuentra previo a la A en la tabla ASCII
    unsigned seed = time(0);
    srand(seed);
    aleatorio(arreglo, 200);
    contar(arreglo,200,letras);
    for (int i = 0; i < 200; i++ ){
        cout << arreglo[i] << " ";
    }
    for (int i = 0; i < 26; i++){
        letra += 1;
        cout << endl<< letra << ": " << letras[i];
    }
}

void problema4(){
    string cadena = "";
    int numero = 0;
    cout << "Ingrese un número: ";
    cin >> cadena;
    numero = conversionCharInt(cadena);
    cout <<"La cadena es: "<< cadena << " Igual a: "<< numero;
}

void problema6(){

}

void problema8(){

}

void problema10(){

}

void problema12(){

}

void problema14(){

}

void problema16(){

}

void problema18(){

}


