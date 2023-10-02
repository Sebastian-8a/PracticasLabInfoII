#include "funciones.h"




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



int  **rotar(int **matriz){
    int **matriz2 = new int* [5];
    for (int i = 0; i < 5; i++){        //creación matriz temporal
        matriz2[i] = new int [5];
    }


    for (int i=0; i< 5; i ++){
        for (int j = 0; j< 5; j++){
            matriz2[i][j] = matriz[4-j][i] ;            //4 ya que es el total de posiciones por comenzar desde 0
        }
    }

    cout << endl;
    for (int fila = 0; fila < 5; fila++){
        for (int columna = 0; columna< 5; columna++){
            cout << matriz2[fila][columna]<< " ";
        }
        cout << endl;
    }
    return matriz2;
}



int factorial(int num){
    int total = 1;
    for (int i = 0; i < num; i ++){
        total *= num - i;
    }

    return total;
}

int caminosPosibles(int n){
    int combinacion  = 0;
    combinacion = (factorial(n*2))/(factorial(n)*factorial(n));
    return combinacion;
}

/*
  n*2 debido a que es la cantidad máxima de movimientos posibles sin importar su orden
  En el denominador n!*n! debido a que es una malla cuadrada y esta fórmula sólo servirá
  en caso de mallas cuadradas
  dividido sobre n a causa que debo escoger los mismos n caminos hacia derecha y n hacia abajo

  combinación debido a que el orden de los elementos no importa
 */



void permutacionlexi(int n){
    int len = 0;
    vector<int> numeros = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> permutacion;        // inicialización variable permutación, pero sin valor, la primera operación que recibe será su asignación de valor
    if (n < 1 || n > 3628800) { // 10!      Número máximo permitido
        cout << "El valor de n está fuera del rango válido." << endl;
            return ;
    }

    do {
        permutacion = numeros; // Copia valor encontrado en numeros
        n--;
    } while (n > 0 && next_permutation(numeros.begin(), numeros.end()));

    /*
    next permutation... calcula la siguiente permutación lexicográfica comparando
    elemento a elemento y modifica el orden en que se encuentra numeros

    - se ejecuta hasta que se logre la permutación del número deseado gracias a
    la condición de n
    */
    cout << "La enésima permutación lexicográfica de los números del 0 al 9 con n = " << n + 1 << " es: ";
    len = permutacion.size();           //Det cant elem del vector
    for (int i = 0; i < len; i++) {
        cout << permutacion[i];
    }
    cout << endl;

    return;
}
