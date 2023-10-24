#ifndef CLASES_H
#define CLASES_H
#include <string>
#include "funciones.h"



using namespace std;

typedef vector<int> vect;

//Clase tablaEnrutamiento
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
    void minDist();         //|
};



//Clase Enrutador
class Enrutador {
private:
    vect conexionesVecinas;     //Vector con 4 espacios inicialmente
    int indice;
    char id;
    TablaEnrutamiento tabla;
public:
    /*
    int posición: índice en los vectores en el cual se encunetra el enrutador objetivo
    */
    Enrutador();
    Enrutador(int index, char identificador);    
    int getIndex();         //Retorno Indice |
    void setIndex(int index);           //Set índice |
    char getId();           //Retorno Id |
    void setId(char identificador);         //Set Id |
    void modificarRuta(int costo, int index);       //Analizar si esta se borra |
    void setTablaEnrutamiento(TablaEnrutamiento tab);
    void agregarRuta(const int posicion, const int costo);          //Agregar Ruta |
    void eliminarRuta(const int posicion);          //eliminar ruta |
    void mostrarConexionesVecinas(vector<char> letras);         //mostrar rutas pasando las conexiones existentes|
    vect * retornarConexionesVecinas();         //retornar dirección de memoria donde se ubican las conexiones
    void agregarFinal();
};







void menu();



#endif // CLASES_H
