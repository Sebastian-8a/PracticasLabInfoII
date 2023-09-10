#include <iostream>

using namespace std;

int calculoPrimo(int);

int main()
{
    int nprimo = 0;
    int primo = 1;
    cout << "Ingrese la posición del número primo que desea conocer: ";
    cin >> nprimo;
    for (int cant = 0; cant <= nprimo; cant++){
        if (cant == nprimo){
            cout << "El primo número "<< nprimo<< " es "<< primo;
        }
        primo =  calculoPrimo(primo);

    }

    return 0;
}

int calculoPrimo(int nuevoPrimo){
    while(bool bandera = true){
        nuevoPrimo += 1;
        for (int i = 2; (i <= ((nuevoPrimo/2)+1))||(i == nuevoPrimo);i++){
            if ((nuevoPrimo!=i) &&((nuevoPrimo % i)==0)){
                break;
            }
            if ((i == (nuevoPrimo/2))||(i == nuevoPrimo)){
                return nuevoPrimo;
            }
        }

    }
}
