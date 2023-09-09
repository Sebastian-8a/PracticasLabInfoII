#include <iostream>

using namespace std;

int main()
{
    int temporal = 0, hora1 = 0, hora2 = 0;
    short int min1 = 0, min2 = 0;
    int horasTot = 0, minTot = 0;

    cout << "Ingrese el valor de la primera hora: ";
    cin >> temporal;
    hora1 = temporal/100;       //Conocer la cantidad de horas
    if (((temporal - (hora1*100))>= 60)|| (hora1 > 23)){          //Evaluar que no se haya ingresado más de 60 minutos o 24 horas
        cout << temporal << " es un tiempo inválido.";
            return 0;
    }
    min1 = temporal - (hora1*100);        //Calcular la cantidad de minutos
    cout << "Ingrese el valor de la segunda hora: ";
    cin >> temporal;
    hora2 = temporal/100;
    if (((temporal - (hora2)*100)>= 60)|| (hora2 > 23)){
            cout << temporal << " es un tiempo inválido.";
                return 0;
    }
    min2 = temporal - (hora2*100);
    horasTot = hora1 + hora2;
    if ((min1 + min2)>= 60){        //Determinar que la posibilidad de que los minutos al sumarse resulten como una hora más
        horasTot += 1;
        minTot = (min1 + min2) - 60;
    }
    else minTot = min1 + min2;
    if (horasTot >23) cout << " los valores ingresados son inválidos.";     //En caso de que la suma de los dos valores resulte mayor a las 24 horas del día
    else
        cout << " La hora es: " << horasTot << minTot;



    return 0;
}
