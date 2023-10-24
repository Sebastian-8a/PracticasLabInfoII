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
    char id;
public:
    /*
    int posición: índice en los vectores en el cual se encunetra el enrutador objetivo

    */
    Enrutador(int index, char identificador);
    int getIndex();         //Retorno Indice |
    void setIndex(int index);           //Set índice |
    char getId();           //Retorno Id |
    void setId(char identificador);         //Set Id |
    void agregarRuta(const int posicion, const int costo);          //Agregar Ruta |
    void eliminarRuta(const int posicion);          //eliminar ruta |
    void mostrarConexionesVecinas(vector<char> letras);         //mostrar rutas pasando las conexiones existentes|
    vect * retornarConexionesVecinas();         //retornar dirección de memoria donde se ubican las conexiones

};


class TablaEnrutamiento{
private:
    vector<vect> enrutadores;
    int cantEnrutadores;
public:
    TablaEnrutamiento();
    vector<vect> *getEnrutadores();
    int getCantEnrutadores();       // |
    void setEnrutador(vect &enrutador,const int pos);        //|
    void eliminarEnrutador(int pos);        //|
    void mostrarEnrutadores(vector<char> letras);

};








#endif // FUNCIONES_H
