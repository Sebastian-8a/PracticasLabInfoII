#include <iostream>

using namespace std;

bool esVocal(char );
bool esCaracter(char);

int main(int argc, char *argv[])
{
    for ( int contador = 1; contador < argc; contador++){
        char caracter = *argv[contador];
        bool condicionLetra = esCaracter(caracter);
        if (condicionLetra){
            bool condicionVocal = esVocal(caracter);
            if (condicionVocal) cout << caracter << " Es una vocal. \n";
            else cout << caracter << " Es una consonante. \n";
        }
        else{
            cout << caracter << " No es una letra \n";
        }
    }
     return 0;
}

bool esVocal(char caracter){
     char vocales[10]={'A','E','I','O','U','a','e','i','o','u'};
     for (int i = 0 ; i < 10 ; i++){
        if (caracter == vocales[i]){
            return true;
        }
     }
     return false;
}

bool esCaracter(char caracter){
     if (((caracter>= 'A') && (caracter<='Z'))||((caracter>='a')&&(caracter<='z'))) return true;
     else return false;
}



