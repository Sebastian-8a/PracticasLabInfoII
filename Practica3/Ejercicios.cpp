#include "funciones.h"

void ejercicio1(){
/*
variables:
    str/
    nombreEntrada: nombre del archivo desde el cuál se va a leer el contenido
    nombreSalida: nombre del archivo en el cual quedará registrado el contenido una vez ha sido codificado
    contenido: contenido encontrado en el archivo leído
    bin: contenido leído en formato binario
    int/
    bloque: tamaño del bloque ingresado
    numBloques: cantidad de bloques que se pueden generar en la cadena leída y convertida en binario
    len: longitud de la cadena binaria
    bool/
    estado: determina el estado de lectura del archivo en caso de ser false, este no se ha
    logrado abrir de forma exitosa debido a que se ha ingresado un nombre erróneo
    bandera: ayuda a determinar si el número del tamaño del bloque es válido o no


*/
    string  nombreSalida , contenido, bin, bloqueTemp1, bloqueTemp2 ;
    int bloque = 0, numBloques = 0, len = 0;
    bool  bandera = false;


    contenido = leer();

    bin = contenidoEnBinario(contenido);
    len = bin.length();

    while (bandera == false){
        cout << "Ingrese el tamaño del bloque: ";
                cin >> bloque;
        if ((len % bloque) != 0){           //Confirmar el caso donde la cadena se pueda dividir totalmente sobre el número del bloqaue
        system("cls");
        cout << "La cadena no puede dividirse completamente en bloques de "<< bloque<< " elementos"<<endl;
            }
        else{
        bandera = true;
            }
    }

    numBloques = len / bloque;
    cout << "El archivo en binario sería:"<< endl<< bin << endl;
    for (int i = 0; i < numBloques; i++){
        bloqueTemp1 = "", bloqueTemp2 = "";
        //len-1 (ultimo indice) -> a -i
        for (int j = 0; j < bloque*2; j++){
            if (j< bloque)
                bloqueTemp1 += bin[i+j];
            else
                bloqueTemp2 += bin[bloque+i+j];
        }

        cout << bloqueTemp1<< endl << bloqueTemp2<< endl;
    }


/*
    cout << "Ingrese el nombre del archivo donde se reflejarán los cambios: ";
    cin >>nombreSalida;
*/}


void ejercicio2(){



}

