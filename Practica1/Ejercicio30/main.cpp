#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int ingresado = -1, intentos = 0;
    int aleatorio = rand() % 101;
    while (ingresado != aleatorio){
        intentos++;
        cout << "\n Ingrese un número: ";
        cin >> ingresado;
        if (ingresado < aleatorio) cout << endl << ingresado << " Es menor al número a adivinar";
                else if (ingresado > aleatorio) cout << endl << ingresado << " Es mayor al número a adivinar";
    }
    cout << "\n Has adivinado! \n El número era: " << aleatorio << "\n Te ha tardado " << intentos << " Intentos";
    return 0;
}
