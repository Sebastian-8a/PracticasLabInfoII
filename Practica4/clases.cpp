#include "clases.h"


Enrutador::Enrutador(){
    indice = 0;
    id = ' ';
    conexionesVecinas.push_back(0);
    conexionesVecinas.push_back(0);
    conexionesVecinas.push_back(0);
    conexionesVecinas.push_back(0);
}

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

void Enrutador::modificarRuta(int costo, int index){
    try {
        conexionesVecinas.at(index) = costo;
    } catch (const exception &) {
        cout<< "\nPreocupese si lee esto\n";
    }

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

void Enrutador::setTablaEnrutamiento(TablaEnrutamiento tab){
    tabla = tab;
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

void TablaEnrutamiento::minDist(){
    for (int i = 0; i < cantEnrutadores; i++){
        dijkstra(enrutadores,i);
    }
}





void menu(){
    vector<char> letras = {'A','B','C','D'};
    Enrutador A(0,'A'),B(1,'B'),C(2,'C'),D(3,'D'),A2, A3,A4,A5;
    TablaEnrutamiento rut;
    //Anexo rutas por defecto
    A.agregarRuta(B.getIndex(),4); A.agregarRuta(C.getIndex(),10);
    B.agregarRuta(A.getIndex(),4); B.agregarRuta(D.getIndex(),1);
    C.agregarRuta(A.getIndex(),10); C.agregarRuta(D.getIndex(),2);
    D.agregarRuta(C.getIndex(),2); D.agregarRuta(B.getIndex(),1);
    //Anexo de rutas conocidas a la tabla
    rut.setEnrutador(*A.retornarConexionesVecinas(),A.getIndex());
    rut.setEnrutador(*B.retornarConexionesVecinas(),B.getIndex());
    rut.setEnrutador(*C.retornarConexionesVecinas(),C.getIndex());
    rut.setEnrutador(*D.retornarConexionesVecinas(),D.getIndex());
    //Mostrar enrutadores en la tabla de enrutamiento
    //rut.mostrarEnrutadores(letras);

    A.setTablaEnrutamiento(rut);
    B.setTablaEnrutamiento(rut);
    C.setTablaEnrutamiento(rut);
    D.setTablaEnrutamiento(rut);

    /*
    rut.minDist();
    rut.mostrarEnrutadores(letras);


    rut.mostrarEnrutadores(letras);
    rut.eliminarEnrutador(B.getIndex());
    letras.erase(letras.begin()+1);
    rut.mostrarEnrutadores(letras);



    A.mostrarConexionesVecinas(letras);
    A.eliminarRuta(1);
    letras.erase(letras.begin()+1);
    A.mostrarConexionesVecinas(letras);


*/

}

