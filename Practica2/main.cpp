#include "zonapruebas.h"

int main()
{
    int opcion = 0;
    cout << "1. Ejercicios. \n"
            "2. Problemas. \n"
            "Ingrese una opción: ";
    cin >> opcion;

    switch (opcion){
    case 1:
        system("cls");          //Comando para limpiar pantalla perteneciente a std
        cout << "1. Ejercicio 2. \n"
                "2. Ejercicio 4 \n"
                "Ingrese una opción: ";
        cin>> opcion;
        switch(opcion){
        case 1:
            cout << "Opción 1";
                break;
        case 2:
            cout << "Opción 2";
                break;
        }


        break;
    case 2:



        break;




    default:
        cout << "Opción inválida. \n Vuelva a ejecutar.";

    }



    return 0;
}
