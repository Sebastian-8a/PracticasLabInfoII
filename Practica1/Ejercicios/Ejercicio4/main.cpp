#include <iostream>

using namespace std;

int main(){

    int A = 0;
    int B = 0;
    cout << "Ingrese un número A: ";
            cin >> A ;
    cout<< endl << "Ingrese un número B: ";
            cin >> B;
    if (A>B){
        cout << endl << "El número menor es " << B << endl;
    }
    else{
        cout << endl << "El número menor es " << A << endl;
    }



    return 0;
}
