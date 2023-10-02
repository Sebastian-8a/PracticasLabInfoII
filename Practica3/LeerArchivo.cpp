#include <iostream>
#include <fstream>
#include <sstream>
#include "funciones.h"
using namespace std;

/* Programa para escribir un numero o una palabra
en un archivo de texto



 Programa para leer un archivo de texto
 caracter por caracter o linea completa
 y convertir un numero leido a una variable entera*/


void leer(){
    string lineas, temp;
    ifstream archivo;         //Instancia de la clase iftream (lectura) para representar el archivo

    archivo.open("archivo1.txt", ios::in);  //Abrir el archivo para lectura
    if (!archivo.is_open()) {
        cout << "Falla." << endl;
        return;  // Exit the program with an error code
    }

    //Leer por linea
    while (! archivo.eof()){            //Mientras que no me encuentre con el final del archivo
        getline(archivo,temp);   //Obtener una linea

        lineas += temp + "\n";

    }

    archivo.close();    //Cerrar el archivo
    ofstream archivo2("archivo1.txt");
    archivo2<< lineas ;
    return;
}
