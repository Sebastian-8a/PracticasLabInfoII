#include "funciones.h"

void ejercicio1(){
/*
variables:
    str/
    nombreEntrada: nombre del archivo desde el cuál se va a leer el contenido
    nombreSalida: nombre del archivo en el cual quedará registrado el contenido una vez ha sido codificado
    contenido: contenido encontrado en el archivo leído
    bin: contenido leído en formato binario
    bloqueOrg: bloque del binario original que será el que determine la condición de modificación al siguiente
    codificado: Bloque final una vez ha sido codificado
    int/
    bloque: tamaño del bloque ingresado
    numBloques: cantidad de bloques que se pueden generar en la cadena leída y convertida en binario
    len: longitud de la cadena binaria
    bool/
    estado: determina el estado de lectura del archivo en caso de ser false, este no se ha
    logrado abrir de forma exitosa debido a que se ha ingresado un nombre erróneo
    bandera: ayuda a determinar si el número del tamaño del bloque es válido o no


*/
    string  nombreSalida , contenido, bin, bloqueOrg, bloqueCodificado, codificado;
    int bloque = 0, numBloques = 0, len = 0, cantCeros = 0, cantUnos = 0;
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
    // cout << "El archivo en binario sería:"<< endl<< bin << endl;     Mostrar esto si se desea ya que no se solicita

    for (int i  = 0; i< bloque; i++){        //toma del primer bloque para invertir los valores
        bloqueOrg += bin[i];
        if (bin[i]== '1')       //conteo de números para realizar la primera modificación
            cantUnos += 1;
        else
            cantCeros += 1;
    }
    codificado += bloqueCodif(2,2,bloqueOrg);       //el 2 solo es para indicar que deben reemplazar cada número por su opuesto

    for (int bloqueNum = 1; bloqueNum< numBloques; bloqueNum++){        //bloqueNum: bloque Número...
        bloqueOrg = "";
        for (int j = (bloque*bloqueNum); j< (bloque*(bloqueNum+1)); j++){       //bloque*bloqueNum: el primer índice a tomar de la cadena
            bloqueOrg += bin[j];
        }
        codificado += bloqueCodif(cantUnos,cantCeros,bloqueOrg);
        cantCeros = 0, cantUnos = 0;
        for (int indice = 0; indice < bloque; indice++){        //Conteo de 1 y 0 de la cadena
            if (bloqueOrg[indice]== '1')
                cantUnos += 1;
            else
                cantCeros += 1;
        }
    }
            // cout <<"El archivo codificado seria: "<<endl<< codificado;   Mostrar esto si se desea ya que no se solicita
    modificar(codificado);
}


void ejercicio2(){



}

