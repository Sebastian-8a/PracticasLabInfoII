#include "menu.h"
#include "funciones.h"

void Menu()
{
    int opcion = 0;
    int opcionB = 0;
    int opcionC = 0;
    while (opcion != 3){
        cout << "1. Ejercicios. \n"
                "2. Problemas. \n"
                "3. Salir del programa. \n"
                "Ingrese una opción: ";
                cin >> opcion;

        switch (opcion){
        case 1:
            while (opcionB != 2){
                system("cls");          //Comando para limpiar pantalla perteneciente a std
                cout << "1. Ejercicio 2. \n"
                        "2. volver al menú inicial. \n"
                        "Ingrese una opción: ";
                        cin>> opcionB;
                switch(opcionB){
                case 1:
                    ejercicio2();
                    break;
                case 2:
                    opcion = 0;
                    break;
                default:
                    system("cls");
                    cout << "Opción inválida. \n Vuelva a ejecutar.";
                }

            }

            break;
        case 2:
            while (opcionC != 1){
                system("cls");          //Comando para limpiar pantalla perteneciente a std
                cout << "1. volver al menú inicial. \n"
                        "2. Problema 2. \n"
                        "3. Problema 4. \n"
                        "Ingrese una opción: ";
                        cin>> opcionC;
                switch(opcionC){
                case 1:
                    opcion = 0;
                    break;
                case 2:

                    problema2();
                    break;
                case 3:
                    problema4();
                    break;
                default:
                    system("cls");
                    cout << "Opción inválida. \n Vuelva a ejecutar.";
                }

            }


            break;




        default:
            system("cls");
            cout << "Opción inválida. \n Vuelva a ejecutar.";

        }

    }


}

