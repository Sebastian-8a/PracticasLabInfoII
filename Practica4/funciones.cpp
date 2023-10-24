#include "funciones.h"


Enrutador::Enrutador(int index, char identificador){
    //4 enrutadores inicialmente
    conexionesVecinas.push_back(0);
    conexionesVecinas.push_back(0);
    conexionesVecinas.push_back(0);
    conexionesVecinas.push_back(0);
    indice = index;
    id = identificador;
}

int Enrutador::getIndex(){
    return indice;
}

void Enrutador::setIndex(int index){
    indice = index;
}

char Enrutador::getId(){
    return id;
}

void Enrutador::setId(char identificador){
    id = identificador;
}

void Enrutador::agregarRuta(int posicion, int costo){
    conexionesVecinas[posicion] = costo;
}

void Enrutador::eliminarRuta(int posicion){
    vect::iterator pos;
    pos = conexionesVecinas.begin() + posicion;
    conexionesVecinas.erase(pos);
}

vect * Enrutador::retornarConexionesVecinas(){
    return &conexionesVecinas;
}

void Enrutador::mostrarConexionesVecinas(vector<char> letras){
    for (const auto letra:letras){
        cout << letra << " ";
    }
    cout << endl;
    for (const auto i: conexionesVecinas){
        cout << i << " ";
    }
    cout << "\n\n";
}







TablaEnrutamiento::TablaEnrutamiento(){
    for (int j = 0; j < 4; j++){
        vect temporal(4);
        for (int i = 0; i< 4;i++){
            temporal[i] = 0;
        }
        enrutadores.push_back(temporal);
    }
    cantEnrutadores = 4;
}

vector<vect> * TablaEnrutamiento::getEnrutadores(){
    return &enrutadores;
}

int TablaEnrutamiento::getCantEnrutadores(){
    return cantEnrutadores;
}

void TablaEnrutamiento::setEnrutador(vect &conexiones,const int pos){
    int len = conexiones.size();
    for (int i = 0; i < len; i++){
        enrutadores[pos][i] = conexiones[i];
    }

}


void TablaEnrutamiento::eliminarEnrutador(int pos){
    vect *elim = &enrutadores[pos];
    vect:: iterator borrar = (*elim).begin();
    for (int i = 0; i < cantEnrutadores ; i++){
        (*elim).erase(borrar);
    }

    cantEnrutadores--;
    auto Elim = (enrutadores.begin()) + pos;
    enrutadores.erase(Elim);

    for (int i = 0; i < cantEnrutadores ; i++){
        elim = &enrutadores[i];
        borrar = (*elim).begin()+pos;
        (*elim).erase(borrar);
    }
}


void TablaEnrutamiento::mostrarEnrutadores(vector<char> letras){
    //vector<char> ::iterator iterador= letras.begin();
    for (auto letra: letras ){
        cout << "   " << letra;
    }
    vector<char> ::iterator iterador= letras.begin();
    for (const auto &i: enrutadores){
        cout << endl << *iterador << " ";
        *iterador ++;
        for (const auto  objeto: i){
            int lenObjt = ((objeto >= 10)|| (objeto < 0)) ? 2:1 ;
            if (lenObjt == 2){
                cout<< " "<< objeto << " ";
            }
            else cout<< "  "<< objeto << " ";
        }
    }
    cout << "\n\n";
}




