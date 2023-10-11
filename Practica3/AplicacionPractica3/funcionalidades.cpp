#include "funcionalidades.h"

void menuInicial(){
    int opcion = 0;
    while (opcion !=3) {
        cout<< "\nIngrese una opcion"
                "\n1. Administrador."
                "\n2. Usuario."
                "\n3. Salir."
                "\nOpcion:";
        cin >> opcion;
        switch(opcion){
        case 1:
            validarAdmin();
            break;
        case 2:
            validarUser();
            break;
        case 3:
            system("cls");
            cout << "\nHasta pronto.";
            break;
        default:
            system("cls");
            cout << "\nOpcion erronea.";
            break;
        }
    }
}


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

void validarUser(){
    system("cls");
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
                cout << "\nIngrese la cedula (10 digitos numericos): ";
                cin>> cedulaIngresada;              //Si hay tiempo validar que sean caracteres numericos
                if (cedulaIngresada.length() == 10){
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
                else{
                    cout << "\nCedula fuera de rango, recuerde son 10 caracteres numericos\n";
                }

            }
            cout << "\nIngrese la clave (4 digitos numéricos): ";
            cin>> claveIngresada;
            if (claveIngresada.length() == 4){
                claveIngresada = cadenaCodifMet1(claveIngresada);
                if (claveIngresada == claves[indice]){
                    cout << "\nSaldo disponible: " << saldos[indice] << endl;
                    if (saldos[indice] >= 1000){
                        saldos[indice] -= 1000;
                        saldos[indice] = menuUser(saldos[indice]);
                    }
                    else{
                        cout << "\nNo posee dinero suficiente para acceder\n";
                    }

                }
                else{
                    cout << "\nClave incorrecta\n";
                }
            }
            else{
                cout << "\nClave fuera de rango, recuerde son 4 caracteres numericos\n";
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


int menuUser(int saldo){
    int opcion = 0;
    unsigned int montoRetirar = 0;
    while (opcion != 3){
        cout <<"\nIngrese una opcion."
                "\n1. Consultar el saldo."
                "\n2. Retirar dinero."
                "\n3. Salir."
                "\nOpcion: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            cout << "\nSu saldo actual es: " << saldo <<endl ;
            break;
        case 2:
            cout << "\nIngrese la cantidad de dinero que desea retirar: ";
            cin >> montoRetirar;
            saldo -= montoRetirar;
            break;
        case 3:
            system("cls");
            break;
        default:
            break;
        }
    }
    return saldo;
}
