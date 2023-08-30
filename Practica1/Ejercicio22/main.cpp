#include <iostream>

using namespace std;

int residuo(int );

int main(){

    int total = 0;
    int seg = 0,min = 0,horas = 0;
    cout << "Ingrese la cantidad total de segundos: ";
    cin >> total;
    seg = total % 60;

    int nuevoTotal = total - seg;
    min = residuo(nuevoTotal);



    return 0;
}

int residuo(int valor){
    if ((valor / 60 ) > 1){
        return valor%60;
    }
    else{
        return valor;
    }
}
