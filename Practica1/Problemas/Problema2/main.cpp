#include <iostream>

using namespace std;

int cantidadBilletes(int, int);
int residuo(int );

int main()
{
    int dinero = 0;
    int denominaciones[11] = {50000,20000,10000,5000,2000,1000,500,200,100,50,0};
    cout << "Ingrese la cantidad de dinero del cual desea conocer las denominaciones equivalentes: ";
    cin >> dinero;
    for (int i = 0; i <11 ; i++){

    }


    return 0;
}

int residuo(int ){


    return 0;
}



int cantidadBilletes(int total, int denominacion){
    return total / denominacion;
}
