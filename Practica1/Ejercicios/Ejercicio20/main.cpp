#include <iostream>

using namespace std;

int invertirNumero(int );

int main() {
    int num = 0;
    cout << "Número a evaluar: " ;
    cin >> num ;
    if (num == invertirNumero(num)){
        cout << endl << num << " Es un número palíndromo ";
    }
    else {
        cout << endl << num << " No es un número palíndromo ";
    }

    return 0;
}

int invertirNumero(int num)
{
    int inv=0;
    while(num>0)
    {
        inv=inv * 10 + (num % 10);
        num = num / 10;
    }
    return inv;
}
