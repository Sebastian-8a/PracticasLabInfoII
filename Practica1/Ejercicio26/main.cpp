#include <iostream>

using namespace std;

int main(){
    int a = 0, b = 0, c = 0;
    cout << "Ingrese la medida del primer lado: ";
    cin >> a;
    cout << "Ingrese la medida del segundo lado: ";
    cin >> b;
    cout << "Ingrese la medida del tercer lado: ";
    cin >> c;
    if (((a+b)>c) && ((a+c)>b) && ((c+b)>a)){

        if ((a == b) && (b == c)) cout << "Se forma un triángulo equilátero";
        else if ( (a != b)&& (b != c) && (a != c)) cout << "Se forma un triángulo escaleno";
        else cout <<"Se forma un triángulo isósceles ";
        return 0;
    }
    cout << "Las longitudes ingresadas no forman un triángulo.";


    return 0;
}
