#include <iostream>

using namespace std;

int main(){

    int A = 0;
    int B = 0;
    //En caso de iniciarlo en 0, el ciclo for itera una vez más de las necesarias

    cout << "Ingrese un número A: ";
            cin >> A ;
    int total = A;
    cout<< endl << "Ingrese su potencia: ";
            cin >> B;
    for (int contador = 1; contador < B ; contador++){
        total *= A;
        }
    cout << endl << A << "^" << B << " = " << total;

    return 0;
}
