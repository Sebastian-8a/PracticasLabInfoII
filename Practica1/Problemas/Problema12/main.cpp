#include <iostream>

using namespace std;

int esPrimo(int);

int main()
{
    int ingresado = 0;

    cout << "Ingrese un número: ";
    cin >> ingresado;
    for (int i =1; i <= ingresado/2;i++){
        if((ingresado%i)==0){
            if (esPrimo(ingresado/i)){
                cout << "El mayor factor primo de "<<ingresado << " es " << ingresado/i;
                return 0;
            }

        }

    }
    return 0;
}

int esPrimo(int numero){
    for (int j = 2; j < numero / 2; j++) {
        if (numero % j == 0) return false;
    }

    return true;
}
