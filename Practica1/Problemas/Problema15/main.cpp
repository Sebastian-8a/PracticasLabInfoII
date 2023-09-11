#include <iostream>

using namespace std;

int main()
{

    int n = 0, valor = 0, fila = 0, columna = 0, k = 0, suma = 0;         //k sirve para contar la mitad de los renglones e ir llenando sin reemplazar posiciones con valor ya asignado
    cout << "Ingrese el tamaño de la espiral: ";
    cin >> n;
    valor = (n * n);
    int matriz[n][n];
    columna =  n-1;

    while(k< n/2){
        for(columna; columna >= fila; columna --){
            matriz[fila][columna]= valor;
            valor --;
        }
        columna++;
        k++;
        fila++;
        for (fila; fila <= n-k; fila++){
            matriz[fila][columna]= valor;
            valor --;
        }
        fila--;
        columna ++;
        for(columna; columna <= fila; columna++){
            matriz[fila][columna]= valor;
            valor --;
        }
        columna--;
        fila--;
        if (fila == k){
            matriz[fila][columna]= valor;
            valor --;
            columna--;
            matriz[fila][columna]= valor;
        }
        else{
            for (fila; fila >= k; fila --){
                matriz[fila][columna]= valor;
                valor --;
            }
        }

       fila++;
        columna--;
    }

    for (int i = 0; i<n ; i++){

            for (int j = 0; j<n ; j++){
                if ((i==n/2 && (j<=(n/2)+1) && (j>=(n/2)-1)) || ((i==(n/2)+1) && (j<=(n/2)+1) && (j>=(n/2)-1))||((i==(n/2)-1)&& (j<=(n/2)+1)&& (j>=(n/2)-1))){
                    cout<<" "<< matriz[i][j]<< " ";
                }
                else
                cout<< matriz[i][j]<< " ";
            }
            cout<< endl;
        }
    valor = 0;
    for (int m = 0; m< n;m++){
            suma += matriz[m][m]    ;
        }


        for (int q=(n-1); q >= 0; q--){
            if(q != n/2){
            suma += matriz[valor][q]    ;
            }
            valor++;
        }
    cout << "La suma es: "<< suma;
    return 0;
}
