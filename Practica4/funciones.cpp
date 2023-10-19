#include "funciones.h"


Enrutador::Enrutador(){
    conexionesVecinas['A'] = -1;
    conexionesVecinas['B'] = -1;
    conexionesVecinas['C'] = -1;
    conexionesVecinas['D'] = -1;
    nombre = ' ';
}

Enrutador::Enrutador(string nom){
    conexionesVecinas['A'] = -1;
    conexionesVecinas['B'] = -1;
    conexionesVecinas['C'] = -1;
    conexionesVecinas['D'] = -1;
    nombre = nom[0];
    conexionesVecinas[nom[0]] = 0;
}

void Enrutador::setNombre(string nombreClase){
    nombre = nombreClase[0];
}

char Enrutador::getNombre() const {
    return nombre;
}

void Enrutador::agregarRuta(char enrutador, int costo){
    conexionesVecinas[enrutador] = costo;
}

void Enrutador::eliminarRuta(const char enrutador){
    conexionesVecinas.erase(enrutador);
}

void Enrutador::mostrarCosto(char enrutador){
    try{
        cout << endl << "El costo al enrutador: "<< enrutador << " es "<< conexionesVecinas.at(enrutador);
    }catch(const exception &e){
        cout << endl<< "No se ha encontrado el enrutador";
        return;
    }
}

mapa Enrutador::retornarConexionesVecinas() const{
    return conexionesVecinas;
}






/*
void TablaEnrutamiento::setRuta(string clave,mapa enrutador){
    rutas[clave[0]] = enrutador;

}*/

void TablaEnrutamiento::setRutas(string clave, mapa conexiones){
    rutas[clave[0]] = conexiones;
}

void TablaEnrutamiento::mostrarRutas(){
    cout << " ";
    for (const auto &ruta: rutas){
        cout << "   " << ruta.first;
    }
    for (const auto &ruta: rutas){

        cout << endl << ruta.first << " ";
        for (const auto objeto : ruta.second){
            int lenObjt = ((objeto.second >= 10)|| (objeto.second < 0)) ? 2:1 ;
            if (lenObjt == 2){
                cout<< " "<< objeto.second << " ";
            }
            else cout<< "  "<< objeto.second << " ";

        }
    }
}




