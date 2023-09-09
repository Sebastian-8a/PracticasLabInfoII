#include <iostream>

using namespace std;

bool busquedaBinaria(int , int , int , int arreglo[]);

int main()
{
    int num1 = 0, num2 = 0, num3 = 0;
    int multiplosNum1[20] = {}, multiplosNum2[20] ={};      //Delimitarlo ya que al dejarlo sin la cantidad determinada generaba modificación en el for
    int cantMultiplosNum1 = 0;
    int inf = 0;
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;
    cout << "Ingrese el tercer número: ";
    cin >> num3;
    for (int i = 1 ; num1 * i < num3; i++){
        multiplosNum1[i] = (num1 * i);
        cantMultiplosNum1 +=1;
    }
    int sup = cantMultiplosNum1;
    for (int i = 1 ; (num2 * i) < num3; i++){
        if (busquedaBinaria(inf, sup, (num2*i),multiplosNum1)){
    cout << "hola mundo";
        }
        multiplosNum2[i] = num2 * i;
    }           //Quise hacer búsqueda binaria, pero ya que no conocía la cantidad de elementos máxima de cada vector, no podía establecer el límite superior




    return 0;
}

bool busquedaBinaria(int inf, int sup, int num, int arreglo[]){
    while (inf <= sup){
        int mitad = (inf + sup) / 2;
        cout << arreglo[mitad];
        if (arreglo[mitad] == num ) return true;
        if (arreglo[mitad] > num ) {
            sup = mitad;
            mitad = (inf + sup) / 2;
        }
        if (arreglo[mitad] < num ) {
            inf = mitad;
            mitad = (inf + sup) / 2;
        }
    }
    return false;
}
