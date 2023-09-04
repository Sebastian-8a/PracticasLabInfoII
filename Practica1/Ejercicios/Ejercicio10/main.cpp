#include <iostream>

using namespace std;

int main(){

    int N = 0;

    cout << "Ingrese un número N: ";
    cin >> N;
    for (int contador = 1; contador <=100; contador++){
        if ((N*contador)<100){
            cout << endl << N*contador;
        }
        else{
            break;
        }

    }


    return 0;
}
