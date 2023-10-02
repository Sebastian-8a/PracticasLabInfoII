#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/* Programa para escribir un numero o una palabra
 * en un archivo de texto*/



/* Programa para leer un archivo de texto
 * caracter por caracter o linea completa
 * y convertir un numero leido a una variable entera*/


int leer()
{
    int numero1, numero2=0;
    char str[256];
    ifstream archivo;         //Instancia de la clase iftream (lectura) para representar le archivo

    archivo.open("archivo1.txt", ios::in);  //Abrir el archivo para lectura
    if (!archivo.is_open()) {
        std::cout << "Falla." << std::endl;
        return 1;  // Exit the program with an error code
    }

    //Leer por linea
    while (! archivo.eof()){            //Mientras que no me encuentre con el final del archivo
        archivo.getline(str,256);   //Obtener una linea
        stringstream val(str);  //Convertir a entero
        val >> numero1;         //Guardar el entero
        cout<<"Numero leido por linea: " <<numero1<<endl;
    }
    archivo.seekg(0);           //Volver al inicio del archivo
    //Leer por caracter
    while(archivo.good()){       //Hasta el fin del archivo
        char temp;
        archivo.get(temp);     //Obtener el caracter
        if (temp != '\n') {
            if(archivo.good()) numero2=numero2*10+temp-'0';  //Convertir el caracter a entero y acumular el valor
        }
    }

    cout<<"Numero leido por caracter: " <<numero2<<endl;

    archivo.close();    //Cerrar el archivo

}
