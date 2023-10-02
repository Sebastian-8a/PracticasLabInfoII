#include "funciones.h"
















int  decimalBinario(int entero){
    unsigned int i = 0, binario = 0, producto = 1;
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


    for (int i = 0; i<8; i++){
        binario += arreglo[7-i] * producto;
        producto *= 10;
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
        lineas += temp + "\n";
    }
    archivo.close();    //Cerrar el archivo

    return lineas;
}

void modificar(string contenido){

}
