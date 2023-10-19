#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <list>


#define quote(nombreClase) #nombreClase         //Macro

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
    list<mapa> rutas;

public:
    TablaEnrutamiento(){};
    void setRuta(mapa conexiones);
    void mostrarRutas();
    void mejorCamino();
};





#endif // FUNCIONES_H
