#include <iostream>

using namespace std;

void collatz(int , int, int);

int main()
{

    int ingresado = 0;
    int serie[]={};



    cout << "Ingrese un número: ";
    cin >> ingresado;







    return 0;
}

void collatz(int arreglo[], int num, int i){

    if ((num%2)==0){
        arreglo[i]= num/2;
    }
    else{
        arreglo[i]= (3*num)+1;
    }
}
