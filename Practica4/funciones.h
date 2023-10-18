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
public:
    Enrutador();
    void agregarRuta(const char enrutador, const int costo);
    void eliminarRuta(const char enrutador);
    void mostrarCosto(const char enrutador);
    mapa retornarConexionesVecinas() const;
    /*
    mapa getConexionesVecinas() const;
    void setConexionesVecinas(const mapa &newConexionesVecinas);*/
};

struct TablaEnrutamiento{
    vector<mapa> rutas;
    void setRuta(const mapa enrutador);
    void mostrarRutas();
};


void leer(vector<string> &datos);





#endif // FUNCIONES_H
