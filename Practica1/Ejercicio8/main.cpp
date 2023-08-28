#include <iostream>

using namespace std;

int main(){

    int num = 0;
    int total = 1;
    //En caso de iniciarlo en 0, el ciclo for itera una vez más de las necesarias

    cout << "Ingrese el número que desea conocer su factorial: ";
            cin >> num ;

    for (int contador = 1; contador <= num ; contador++){
        total *= contador;
    }
    cout << endl << num << "! = " << total;


    return 0;
}
