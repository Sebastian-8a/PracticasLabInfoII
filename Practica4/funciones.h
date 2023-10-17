#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef map<char,int> mapa;


// Clase Enrutador
class Enrutador {

private:
    mapa conexionesVecinas;
    mapa tablaEnrutamiento;
public:
    Enrutador();
    void agregarRuta(const char enrutador, const int costo);
    void eliminarRuta(const char enrutador);
    void mostrarCosto(char enrutador);
    /*
    mapa getConexionesVecinas() const;
    void setConexionesVecinas(const mapa &newConexionesVecinas);*/
};




void leer(vector<string> &datos);





#endif // FUNCIONES_H
