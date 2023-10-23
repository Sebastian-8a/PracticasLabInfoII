#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <queue>

#define quote(nombreClase) #nombreClase         //Macro
const int INF = INT_MAX; // Valor para representar la distancia infinita

using namespace std;

typedef map<char,int> mapa;


//Clase Enrutador
class Enrutador {
private:
    mapa conexionesVecinas;
    char nombre;
public:
    Enrutador();
    Enrutador(string A);
    void setNombre(string nombreClase);
    char getNombre() const;
    void agregarRuta(const char enrutador, const int costo);
    void eliminarRuta(const char enrutador);
    void mostrarCosto(const char enrutador);
    mapa retornarConexionesVecinas() const;

};


class TablaEnrutamiento{
private:
    vector<mapa> enrutadores;

public:
    TablaEnrutamiento(){};
    void setEnrutador(mapa enrutador);
    void mostrarEnrutadores();
    void mejorCamino();
};





#endif // FUNCIONES_H
