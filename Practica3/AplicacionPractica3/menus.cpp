#include "funciones.h"

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
            cout << "\nHola Mundo";
            break;
        case 2:
            cout << "\nHola Mundo";
            break;
        case 3:
            system("cls");
            cout << "\nHasta pronto.";
        default:
            system("cls");
            cout << "\nOpcion erronea.";
            break;
        }
    }




}
