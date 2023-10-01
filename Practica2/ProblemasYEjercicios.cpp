#include "funciones.h"



void ejercicio2(){
    double prom = 0.0, sum = 0.0;
    double *promedio = &prom, *suma = &sum;
    double arreglo[5] = {5,4,3,2,1};        //Ingresar datos que desee calcular aquí


    fun_c(arreglo,5,promedio,suma);
    cout << "El promedio de los números:";
        for (int k = 0; k < 5; k++) cout << " " << arreglo[k];
    cout << " es: " << prom;

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
    string palabra = "";
    cout<< "Ingrese una cadena de caracteres: ";
    while (true){
    getline(cin,palabra);             //acción, donde se almacena, hasta donde lee
        if (palabra != "")
        break;
    }
    string newPalabra = minusAMayus(palabra);
    cout << "Original: "<< palabra<< ". En mayuscula: "<<newPalabra;
}

void problema8(){
    string letras = "";
    string ingresado = "";
    cout << "Ingrese una cadena de caracteres: ";
    while (true){
        getline(cin,ingresado);             //acción, donde se almacena, hasta donde lee
        if (ingresado != "")
        break;
    }
    int numeros = 0;
    int  *ptrNum =&numeros;
    letras = texto(ingresado, ptrNum);          //Se debe ingresar antes del 0 un numero diferente ya que al hacer la conversión, se adapta a entero y no vale un 0 a la izq o simplemente se cambia por cadena de caracteres
    cout<< "Original: "<< ingresado<< endl<< "Texto: "<< letras<< endl<< "Numero: "<< numeros;
}

void problema10(){
    string ingresado = "";
    int resultado  = 0;
    cout <<"Ingrese una cadena de numeros romanos: " ;
    while (true){
        getline(cin,ingresado);             //acción, donde se almacena, hasta donde lee
        if (ingresado != "")
        break;
    }
    resultado = romanoArabigo(ingresado);
    cout << "El número ingresado fue: " << ingresado<< endl;
            cout <<"Que corresponde a: "<< resultado;
}

void problema12(){
        int n= 0;
        cout << "Ingrese el tamaño de cada fila o columna: ";
        cin >> n;

        int** matriz = new int *[n];
        for (int i = 0; i < n; i++){
            matriz[i] = new int [n];
            }

        for (int fila = 0; fila < n ; fila++){
            for (int columna = 0; columna < n; columna++){
                cout << "Ingrese el valor de la fila "<< fila<< " y columna "<< columna<< " : ";
                cin >> matriz[fila][columna];
        }
            }
        for (int fila = 0; fila < n ; fila++){
            for (int columna = 0; columna < n; columna++){
            cout << matriz[fila][columna] << " ";
            }
            cout << endl;
        }
        if (cuadradoMagico(matriz,n)) cout << "La matriz ingresada es cuadrado magico";
        else cout << "La matriz ingresada NO es cuadrado magico";

        for (int i = 0; i < n; i++) delete[] matriz[i];
        delete[] matriz;

}

void problema14(){
        int **matriz = new int* [5];
        int **nuevaMatriz = new int* [5];
        int num = 1;
        /*
    int contador = 1, limSup = 26;
    unsigned seed = time(0);
    srand(seed);                No se puede generar el rand ya que nada nos asegura que se generen todos 1-25*/


        for (int i = 0; i < 5; i++){
            matriz[i] = new int [5];
        }

        for (int fila = 0; fila < 5; fila++){
            for (int columna = 0; columna< 5; columna++, num++){
            matriz[fila][columna]= num;
            }
        }
        cout << "La matriz original es: "<< endl;
        for (int fila = 0; fila < 5; fila++){
            for (int columna = 0; columna< 5; columna++){
            cout << matriz[fila][columna]<< " ";
            }
            cout << endl;
        }
        cout << "La matriz rotada 90 grados: ";
        nuevaMatriz = rotar(matriz);
        cout << "La matriz rotada 180 grados: ";
        nuevaMatriz = rotar(nuevaMatriz);
        cout << "La matriz rotada 270 grados: ";
        nuevaMatriz = rotar(nuevaMatriz);

        for (int i = 0; i < 5; i++) delete[] nuevaMatriz[i];
        delete[] nuevaMatriz;
        for (int i = 0; i < 5; i++) delete[] matriz[i];
        delete[] matriz;

}

void problema16(){
        int n = 0;
        cout << "Ingrese el tamaño de la malla CUADRADA: ";
                cin >> n;
        cout << "Para una malla de "<< n << "x" << n << " puntos hay " << caminosPosibles(n) << " caminos posibles.";

}

void problema18(){
        int n = 0 ;
        cout << "Ingrese el valor de n: ";
        cin >> n;
        permutacionlexi(n);
}


