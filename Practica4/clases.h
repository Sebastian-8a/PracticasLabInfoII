#ifndef CLASES_H
#define CLASES_H
#include <string>
#include "funciones.h"



using namespace std;

typedef vector<int> vect;

//Clase tablaEnrutamiento
class TablaEnrutamiento{
private:
    vector<vect> conexionesOrg;
    vector<vect> caminosCortos;
    int cantEnrutadores;
public:
    TablaEnrutamiento();
    vector<vect> *getEnrutadores();
    vector<vect> *getCaminos();
    int getCantEnrutadores();       // |
    void aumentarCantEnrutadores();
    void setEnrutador(vect &enrutador,const int pos);        //|
    void eliminarEnrutador(int pos,vector<string> &letras);        //|
    void mostrarEnrutadores(vector<string> letras);
    void minDist();         //|
    void pushBackConexiones();
    void vaciarCaminosCortos();
};



//Clase Enrutador
class Enrutador {
private:
    vect conexiones;     //Vector con 4 espacios inicialmente
    int indice;
    string id;
    vect tabla;
public:
    /*
    int posición: índice en los vectores en el cual se encunetra el enrutador objetivo
    */
    Enrutador();
    Enrutador(int index, string identificador);
    int getIndex();         //Retorno Indice |
    void setIndex(int index);           //Set índice |
    string getId();           //Retorno Id |
    void setId(string identificador);         //Set Id |
    void modificarRuta(int costo, int index);       //Analizar si esta se borra |
    void setTablaEnrutamiento(TablaEnrutamiento tab);           //|
    void agregarRuta(const int posicion, const int costo);          //Agregar Ruta |
    void eliminarRuta(const int posicion);          //eliminar ruta |
    void mostrarConexionesVecinas(vector<string> letras);         //mostrar rutas pasando las conexiones existentes|
    void mostrarTabla(vector<string> letras);
    vect * retornarConexionesVecinas();         //retornar dirección de memoria donde se ubican las conexiones
    void pushBackConexionesTabla();
};



//void actualizarTablas(TablaEnrutamiento tabla, vector <Enrutador> enrutadores);



void menu();
void eliminar(vector<Enrutador *> *Enrutadores, vector<string> *letras, TablaEnrutamiento *rut);
void agregar(vector<string> *letras,vector<Enrutador *> *Enrutadores,  Enrutador & punteroEnrut);

#endif // CLASES_H
