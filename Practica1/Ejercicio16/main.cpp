#include <iostream>

using namespace std;

int main(){

    int contador = 0;
    int numIngresado = 1;
    float  suma = 0;

    while (numIngresado != 0){
        cout << "Ingrese un número: ";
        cin >> numIngresado;
        if (numIngresado != 0){
            suma += numIngresado;
            contador++;
            cout << endl << "El promedio de los números ingresados al momento es: " << (suma/contador);
                cout << endl << "En caso de desear detenerse ingrese el número 0 " << endl ;
        }
    }



    return 0;
}
