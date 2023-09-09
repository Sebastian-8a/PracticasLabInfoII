#include <iostream>

using namespace std;

bool busqueda(int arreglo[], int , int);

int main()
{
    int num1 = 0, num2 = 0, num3 = 0;
    int multiplosNum1[20] = {}, multiplosNum2[20] ={};      //Delimitarlo ya que al dejarlo sin la cantidad determinada generaba modificación en el for
    int cantMultiplosNum1 = 0, suma = 0;
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;
    cout << "Ingrese el tercer número: ";
    cin >> num3;
    for (int i = 1 ; num1 * i < num3; i++){
        multiplosNum1[i] = (num1 * i);
        cantMultiplosNum1 +=1;
        if (i!= 1)cout << " + "<< multiplosNum1[i] ;
        else cout << multiplosNum1[i] ;
        suma += multiplosNum1[i];
    }
    for (int i = 1 ; (num2 * i) < num3; i++){
        if (busqueda(multiplosNum1, (num2*i),cantMultiplosNum1));       //Analizar si el número ya se encuentra en el otro arreglo
        else {
            multiplosNum2[i] = num2 * i;
            cout << " + "<< multiplosNum2[i];
            suma += multiplosNum2[i];
        }


    }
    cout << " = " << suma;



    return 0;
}

bool busqueda(int arreglo[], int num , int len){
    for (int k = 0; k <= len ; k++){

        if (arreglo[k] == num) {
            return true;
        }
    }
    return false;
}
