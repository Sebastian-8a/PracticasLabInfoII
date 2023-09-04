#include <iostream>

using namespace std;

int main(){

    int N = 0;
    cout << "Ingrese el tamaño que desea tenga el cuadrado: " ;
    cin >> N;
    for (int contador = 0; contador < N; contador++) cout << "+";
    for (int contador = 0; contador < (N - 2); contador++){
        cout << "\n";
        for (int i = 0; i < N; i ++){
            if ((i == 0) or (i == N-1) ){
                cout << "+";
            }
            else{
               cout << " ";
            }
        }
    }
    cout << "\n";
    for (int contador = 0; contador < N; contador++) cout << "+";


    return 0;
}
