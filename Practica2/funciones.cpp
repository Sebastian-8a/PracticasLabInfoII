#include "funciones.h"

void Funciones()
{

}
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
