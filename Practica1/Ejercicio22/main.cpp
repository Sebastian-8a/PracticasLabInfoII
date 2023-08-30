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
        cout << endl << " En " << total << " segundos hay " << seg << " seg y " << min << " minutos"        ;
        return 0;
    }
    min = nuevoTotal % 60;
    horas = nuevoTotal-min;
    cout << endl << " En " << total << " segundos hay " << seg << " seg, " << min << " minutos y " << horas << " horas." ;
    //if ((nuevoTotal-min)>= 60){

    //}



    return 0;
}


