#include "funcionalidades.h"


void validarAdmin(){
    string leido, clave, ingresado;
    int opcion = 0;
    leido = leer("sudo.txt");
    clave = bloqueDecodifMet1(leido,4);
    while (opcion != 2){
        cout <<"\nIngrese una opcion."
                "\n1. Clave."
                "\n2. Salir."
                "\nOpcion: ";
        cin>> opcion;
        switch(opcion){
        case 1:
            cout << "Ingrese la clave: ";
            cin >> ingresado;
            if (ingresado == clave){
                menuAdmin();
            }
            else{
                cout << "Clave erronea\n";
            }
            break;
        case 2:
            system("cls");
            break;
        default:
            system("cls");
            cout << "Opcion invalida";
            break;
        }
    }

}

void menuAdmin(){
    cout << "Hola Mundo bien\n";

}


void validarUser(){
    vector<string> cedulas, claves;
    vector<int> saldos;
    int opcion = 0, cantUsuarios = 0 ;
    string *usuarios= new string [5];       //Número máximo de usuarios (puede ser modificado)
    string  cedulaIngresada, claveIngresada;
    cantUsuarios = leerUsuarios(usuarios);

    for(int i = 0; i < cantUsuarios ; i++){
        int len = usuarios[i].length();
        cedulas.push_back(usuarios[i].substr (0,10)) ;
        claves.push_back(usuarios[i].substr(11,32));
        saldos.push_back(stoi(usuarios[i].substr(44, (len - 44))));
    }
    delete[] usuarios;

    while (opcion != 2){
        bool validacion = false;
        int indice = 0;
        cout <<"\nIngrese una opcion."
                "\n1. Ingresar usuario y clave."
                "\n2. Salir."
                "\nOpcion: ";
        cin>> opcion;
        switch(opcion){
        case 1:
            while(validacion != true){
                cout << "\nIngrese la cedula: ";
                cin>> cedulaIngresada;
                for (const auto & cedula : cedulas){
                    if (cedula == cedulaIngresada){
                        validacion = true;
                        break;
                    }
                    indice++;
                }
                if(validacion != true){
                    cout << "\nNo se ha encontrado un usuario con la cédula ingresada\n";
                }
            }
            cout << "\nIngrese la clave: ";
            cin>> claveIngresada;
            claveIngresada = cadenaCodifMet1(claveIngresada);
                if (claveIngresada == claves[indice]) cout << "clave correcta \n";
            break;
        case 2:
            system("cls");
            break;
        default:
            system("cls");
            cout << "Opcion invalida";
            break;
        }
    }



}
