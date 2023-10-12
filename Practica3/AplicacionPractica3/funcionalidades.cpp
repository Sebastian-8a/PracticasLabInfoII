#include "funcionalidades.h"

void menuInicial(){
    int opcion = 0;
    while (opcion !=3) {
        vector<string> cedulas, claves;
        vector<int> saldos;
        int cantUsuarios = 0 ;
        string *usuarios= new string [5], saldoCodif;       //Número máximo de usuarios (puede ser modificado)
        cantUsuarios = leerUsuarios(usuarios);
        for(int i = 0; i < cantUsuarios ; i++){
            int len = usuarios[i].length();
            cedulas.push_back(usuarios[i].substr (0,10)) ;
            claves.push_back(usuarios[i].substr(11,32));
            saldoCodif = (usuarios[i].substr(44, (len - 44)));
            saldoCodif = bloqueDecodifMet1(saldoCodif);
            saldos.push_back(stoi(saldoCodif));
        }
        delete[] usuarios;

        cout<< "\nIngrese una opcion"
                "\n1. Administrador."
                "\n2. Usuario."
                "\n3. Salir."
                "\nOpcion: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            validarAdmin(cedulas, claves,saldos);
            break;
        case 2:
            validarUser(cedulas, claves,saldos);
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


void validarAdmin(vector<string> cedulas, vector<string> claves, vector<int> saldos){
    system("cls");
    string leido, ingresado;
    int opcion = 0;
    leido = leer("sudo.txt");
    //clave = bloqueDecodifMet1(leido,4);
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
            ingresado = cadenaCodifMet1(ingresado);
            if (ingresado == leido){
                menuAdmin(cedulas, claves, saldos);
                opcion = 2;
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

void validarUser(vector<string> cedulas, vector<string> claves, vector<int> saldos){
    system("cls");
    int opcion = 0;
    string  cedulaIngresada, claveIngresada;
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


void menuAdmin(vector<string> cedulas, vector<string> claves, vector<int> saldos){
    system("cls");
    int opcion = 0;

    while(opcion !=3){
        string nueCedula, nueClave;
        int nueSaldo = 0, indice = 0;
        bool validacion = true;

        cout << "\nIngrese una opcion."
                "\n1. Agregar un usuario nuevo."
                "\n2. Consignar valor a cuenta de usuario."
                "\n3. Salir."
                "\nOpcion: ";
        cin >> opcion;
        switch(opcion){
        case 1:         //Acciones para ingresar usuario nuevo
            while(validacion != false){
                validacion = false;
                cout << "\nIngrese la cedula (10 digitos numericos): ";
                cin>> nueCedula;              //Si hay tiempo validar que sean caracteres numericos
                if (nueCedula.length() == 10){
                    for (const auto & cedula : cedulas){
                        if (cedula == nueCedula){
                            validacion = true;
                            break;
                        }
                    }
                    if(validacion == true){
                        cout << "\nSe ha encontrado un usuario con la cédula ingresada\n";
                    }
                    else{
                        for (const char caracter : nueCedula){
                            if(isdigit(caracter));
                            else{
                                cout << "\nIngrese unicamente caracteres numericos";
                                validacion = true;
                                break;
                            }
                        }
                    }
                }
                else{
                    cout << "\nCedula fuera de rango, recuerde son 10 caracteres numericos\n";
                    validacion = true;
                }
            }
            cedulas.push_back(nueCedula);
            while(validacion != true){
                cout << "\nIngrese su clave (4 digitos numericos): ";
                cin >> nueClave;
                if (nueClave.length() == 4){
                    for (const char & esNum : nueClave){
                        if (isdigit(esNum));
                        else{
                            validacion = true;
                            break;
                        }
                    }
                    if(validacion == true){
                        cout << "\nClave ingresada erronea, ingrese unicamente caracteres numericos.\n";
                        validacion = false;
                    }
                    else{
                        validacion = true;
                    }
                }
                else{
                    cout << "\nClave fuera de rango (recuerde son 4 digitos numéricos)\n";
                }
            }
            claves.push_back(nueClave);
            while(validacion != false){
                string nueSaldoStr;
                cout << "\nIngrese el saldo del usuario: ";
                cin >> nueSaldoStr;
                for (const char dato : nueSaldoStr){
                    if (isdigit(dato));
                    else{
                        validacion = false;
                        break;
                    }
                }
                if (validacion == false){
                    cout << "\nIngrese unicamente caracteres numericos.\n";
                    validacion = true;
                }
                else{
                    nueSaldo = stoi(nueSaldoStr);
                    if ( nueSaldo >= 0){
                        validacion = false;
                    }
                    else{
                        cout << "\nAsegurese de ingresar un valor de dinero positivo.\n";
                    }
                }
            }
            saldos.push_back(nueSaldo);
            break;
        case 2:         //acciones consignar dinero
            while(validacion != false){
                string cedulaIngresada;

                cout << "\nIngrese la cedula (10 digitos numericos): ";
                cin>> cedulaIngresada;              //Si hay tiempo validar que sean caracteres numericos
                if (cedulaIngresada.length() == 10){
                    for (const auto & cedula : cedulas){
                        if (cedula == cedulaIngresada){
                            validacion = false;
                            break;
                        }
                        indice++;
                    }
                    if(validacion != false){
                        cout << "\nNo se ha encontrado un usuario con la cédula ingresada\n";
                    }
                }
                else{
                    cout << "\nCedula fuera de rango, recuerde son 10 caracteres numericos\n";
                }
            }


            saldos[indice] += nueSaldo;
            break;
        case 3:
            system("cls");
            break;
        default:
            system("cls");
            cout << "\nOpcion invalida.\n";
            break;
        }
    }


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
            system("cls");
            cout << "\nOpcion invalida.\n";
            break;
        }
    }
    return saldo;
}
