#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <vector>


const int INF = INT_MAX; // Valor para representar la distancia infinita

using namespace std;

typedef vector<int> vect;


//Clase Enrutador
class Enrutador {
private:
    vect conexionesVecinas;     //Vector con 4 espacios inicialmente
    int indice;
public:
    Enrutador(int index);
    int getIndex();
    void agregarRuta(const int posicion, const int costo);
    void eliminarRuta(const int posicion);
    void mostrarConexionesVecinas();
    vect retornarConexionesVecinas() const;

};


class TablaEnrutamiento{
private:
    vector<vect> enrutadores;
    int cantEnrutadores;
public:
    TablaEnrutamiento();
    vector<vect> *getEnrutadores();
    int getCantEnrutadores();
    void setEnrutador(vect enrutador,const int pos);
    void eliminarEnrutador(int pos);
    void mostrarEnrutadores();

};








#endif // FUNCIONES_H
