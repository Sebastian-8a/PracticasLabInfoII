#include <iostream>

using namespace std;

int main(){

    int N = 0 ;

    cout << "Ingrese un número N: ";
            cin >> N;
    if((N%2)!=0){
    cout << endl << N << " Es impar";
    }
    else{
    cout << endl << N << " Es par";
    }

    return 0;
}
