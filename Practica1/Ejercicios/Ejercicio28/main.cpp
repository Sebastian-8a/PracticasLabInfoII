#include <iostream>

using namespace std;

int main(){
    int N = 0;
    float suma = 0.0;
    float denominador = 1;
    cout << "Ingrese un número para realizar la aproximación: ";
    cin >> N;
    for (int contador = 0; contador < N ; contador ++ ){

        if ((contador %2)==0) {
            suma += 1/denominador;
        }
        else{
            suma -= 1/denominador;
        }
        denominador += 2;
    }
    cout << 4 * suma;

    return 0;
}
