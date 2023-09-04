#include <iostream>

using namespace std;



int main(){

    int total = 0;
    int seg = 0,min = 0,horas = 0;
    cout << "Ingrese la cantidad total de segundos: ";
    cin >> total;
    seg = total % 60;

    int nuevoTotal = total - seg;
    if (nuevoTotal == 60){
        min = 1;
        cout << endl << " En " << total << " segundos hay " << min << " minutos y " << seg << " seg.";
        return 0;
    }
    nuevoTotal /= 60;
    min = nuevoTotal % 60;
    horas =  nuevoTotal - min;
    horas = horas / 60;
    cout << endl << " En " << total << " segundos hay " << horas << " horas, " << min << " minutos y " << seg << " seg." ;


    return 0;
}


