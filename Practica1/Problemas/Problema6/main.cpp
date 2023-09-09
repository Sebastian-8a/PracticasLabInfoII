#include <iostream>

using namespace std;

int factorial(int);

int main()
{
    int aprox = 0;
    float suma = 0;
    cout << "Ingrese el número de elementos usados en la aproximación: ";
    cin >> aprox;
    if (aprox == 0){
        cout << "e es aproximadamente 0";
        return 0;
    }

    for (int j = 0; j < aprox; j++){
        suma += 1.0/ factorial(j);
    }

    cout << "e es aproximadamente " << suma;

    return 0;
}

int factorial(int num){
    int suma2 = 1;
    for (int i =1 ; i <= num; i++){
        suma2 *= i;
    }
    return suma2;
}
