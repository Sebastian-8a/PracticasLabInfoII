#include "funciones.h"




string  decimalBinario(int entero){
/*
Función que retorna en forma de string el equivalente en binario de un entero que se ingrese
en este caso se ingresa un caracter de tipo char
*/
    unsigned int i = 0;
    string binario = "";
    short int arreglo[8] = {};  // 8 debido a que es la cantidad de bits contenida en 1 byte
    while (entero != 1){        //ciclo while para generar la conversión de entero a binario
        if ((entero%2) == 1){
            arreglo[7-i] = 1;
            entero = (entero - 1) /2;
        }
        else{
            arreglo[7-i] = 0;
            entero /= 2;
        }
        i ++;
    }
    arreglo[7-i] = 1;

    for (int j = 0; j<8; j++){
        binario += to_string(arreglo[j]);
    }

    return binario;
}



string leer(string nombreArchivo){
    string lineas, temp;
    ifstream archivo;         //Instancia de la clase iftream (lectura) para representar el archivo

    archivo.open(nombreArchivo, ios::in);  //Abrir el archivo para lectura
    if (!archivo.is_open()) {
        cout << "Falla." << endl;
        //return;   Exit the program with an error code         evaluar try / except
    }

    //Leer por linea
    while (! archivo.eof()){            //Mientras que no me encuentre con el final del archivo
        getline(archivo,temp);   //Obtener una linea
        lineas += temp;
    }
    archivo.close();    //Cerrar el archivo

    return lineas;
}

void modificar(string contenido){
    ofstream archivo2("archivo1.txt");
    archivo2<< contenido ;
}


string contenidoEnBinario(string contenido){
/*
Función que se encarga de retornar como una cadena str el equivalente en binario de cada
elemento perteneciente a la cadena inicial
El str retornado será lineal, es decir, no tendrá caracteres separadores entre si, se comprenderá
que por cada 8 caracteres contiguos, esto representará un byte / caracter de la cadena
*/
    short int len = contenido.length();
    string binario = "";
    for (int i = 0; i < len; i++){
        binario += decimalBinario(contenido[i]);
    }
    return binario;
}








