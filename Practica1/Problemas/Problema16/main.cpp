#include <iostream>

using namespace std;

int collatz( int);
int numanterior(int num);

int main()
{

    int ingresado = 0, cantTerminos = 0, terminos2 = 0, num = 0, menor = 0;
    int temporal[200]={};        //Al ingresar valores al arreglo se me modificaba una variable externa (Hipótesis: la posición de memoria coincidía)
    bool bandera = true;


    cout << "Ingrese un número: ";
    cin >> ingresado;
    num = ingresado;

    while (bandera ==  true){
        num =  numanterior(num);
        if (num < ingresado){
            bandera = false;
            temporal[terminos2] = num;
            cantTerminos++;
        }
        else{
            temporal[terminos2] = num;
            terminos2++;
            cantTerminos++;
            cout <<endl<< temporal[terminos2];
        }
    }
    menor = num;
    cout << num<<": ";
    for ((terminos2);terminos2 > 0; terminos2--){
        cout << temporal[terminos2]<< ", ";
    }

    while (bandera == false){
        num = collatz(num);
        cantTerminos++;
        if (num !=1){
            cout<< num << ", ";

        }
        else{
            bandera = true;
            cout << num;
        }
    }
    cout << endl<< " El número previo menor que " << ingresado << " es " << menor
         << " y genera una cadena de " << cantTerminos << "Términos";


    return 0;
}

int collatz( int num){

    if ((num%2)==0){
        return num/2;
    }
    else{
        return (3*num)+1;
    }
}

int numanterior(int num){
    if((((num-1)%3)==0)&&(((num-1)/3)%2)!=0){
        return ((num-1)/3);
    }
    return num*2;
}




/*Algunos números generan que el programa creshee a causa que encontrar su número previo que
sea menor puede encontrarse demasiado lejos, como el caso del 7, 21

*/
