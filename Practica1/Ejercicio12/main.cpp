#include <iostream>

using namespace std;

int main(){

    int A = 0;
    int potencia = 1;
    cout << "Ingrese un número A: ";
            cin >> A ;
    for (int contador = 1; contador <= 5 ; contador++){
        potencia *= A ;
        cout << endl << A << "^" << contador << " = "<< potencia;
    }

    return 0;
}
