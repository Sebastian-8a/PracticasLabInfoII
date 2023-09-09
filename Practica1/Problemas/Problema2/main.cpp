#include <iostream>

using namespace std;


int main()
{
    int total = 0;
    int residuo = 0;
    int denominaciones[10] = {50000,20000,10000,5000,2000,1000,500,200,100,50};
    cout << "Ingrese la cantidad de dinero del cual desea conocer las denominaciones equivalentes: ";
    cin >> total;
    cout << total << " Son: ";

    for (int i = 0; i <11 ; i++){
    residuo = total % denominaciones[i];
    total -= residuo;
    if (i != 10){
        cout << endl << denominaciones[i] << " : " << total / denominaciones[i];
        total = residuo;}
    else{
        cout << endl << "Faltante : " << residuo ;
    }

    }


    return 0;
}
