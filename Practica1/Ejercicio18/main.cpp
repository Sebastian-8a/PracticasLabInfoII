#include <iostream>

using namespace std;

int main(){

    int ingresado = 0;
    int suma = 0 ;
    int num = 1;
    cout << "Ingrese un número: ";
    cin >> ingresado;
    while (suma < ingresado){
        suma += num;
        num += 2;
    }
    if (suma == ingresado){
        cout << endl << ingresado << " Es un cuadrado perfecto";
    }
    else{
        cout << endl << ingresado << " NO es un cuadrado perfecto";
    }

    return 0;
}
