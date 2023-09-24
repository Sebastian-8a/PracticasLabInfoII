#include "menu.h"
#include "funciones.h"

void Menu()
{
    int opcion = 0;
    int opcionB = 0;
    int opcionC = 0;
    while (opcion != 3){
        cout << "\n 1. Ejercicios. \n"
                "2. Problemas. \n"
                "3. Salir del programa. \n"
                "Ingrese una opción: ";
                cin >> opcion;

        switch (opcion){
        case 1:
            system("cls");      //Comando para limpiar pantalla perteneciente a std
            while (opcionB != 2){

                cout << "\n 1. Ejercicio 2. \n"
                        "2. volver al menú inicial. \n"
                        "Ingrese una opción: ";
                        cin>> opcionB;
                switch(opcionB){
                case 1:
                    system("cls");
                    ejercicio2();
                    break;
                case 2:
                    opcion = 0;
                    system("cls");
                    break;
                default:
                    system("cls");
                    cout << "Opción inválida. \n Vuelva a ejecutar.";
                }

            }

            break;
        case 2:
            system("cls");
            while (opcionC != 1){
                //Comando para limpiar pantalla perteneciente a std
                cout << "\n 1. volver al menú inicial. \n"
                        "2. Problema 2. \n"
                        "3. Problema 4. \n"
                        "4. Problema 6. \n"
                        "5. Problema 8. \n"
                        "6. Problema 10. \n"
                        "7. Problema 12. \n"
                        "8. Problema 14. \n"
                        "9. Problema 16. \n"
                        "10. Problema 18 \n"
                        "Ingrese una opción: ";
                        cin>> opcionC;
                switch(opcionC){
                case 1:
                    system("cls");
                    opcion = 0;
                    break;
                case 2:
                    system("cls");
                    problema2();
                    break;
                case 3:
                    system("cls");
                    problema4();
                    break;
                case 4:
                    system("cls");
                    problema6();
                    break;
                case 5:
                    system("cls");
                    problema8();
                    break;
                case 6:
                    system("cls");
                    problema10();
                    break;
                case 7:
                    system("cls");
                    problema12();
                    break;
                case 8:
                    system("cls");
                    problema14();
                    break;
                case 9:
                    system("cls");
                    problema16();
                    break;
                case 10:
                    system("cls");
                    problema18();
                    break;
                default:
                    system("cls");
                    cout << "Opción inválida. \n Vuelva a ejecutar.";
                }

            }


            break;



        case 3:
            system("cls");
            cout << "Hasta pronto";
            break;
        default:
            system("cls");
            cout << "Opción inválida. \n Vuelva a ejecutar.";

        }

    }


}

