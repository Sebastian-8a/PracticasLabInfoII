#include "clases.h"


Enrutador::Enrutador(){
    indice = -1;
    id = "";
    conexiones.push_back(0);conexiones.push_back(0);conexiones.push_back(0);conexiones.push_back(0);
    tabla.push_back(0);tabla.push_back(0);tabla.push_back(0);tabla.push_back(0);
}

Enrutador::Enrutador(int index, string identificador){
    //4 enrutadores inicialmente
    conexiones.push_back(0);conexiones.push_back(0);conexiones.push_back(0);conexiones.push_back(0);
    tabla.push_back(0);tabla.push_back(0);tabla.push_back(0);tabla.push_back(0);
    indice = index;
    id = identificador;
}

int Enrutador::getIndex(){
    return indice;
}

void Enrutador::setIndex(int index){
    indice = index;
}

string Enrutador::getId(){
    return id;
}

void Enrutador::setId(string identificador){
    id = identificador;
}

void Enrutador::modificarRuta(int costo, int index){
    try {
        conexiones.at(index) = costo;
    } catch (const exception &) {
        cout<< "\nPreocupese si lee esto\n";
    }

}

void Enrutador::agregarRuta(int posicion, int costo){
    conexiones[posicion] = costo;
}

void Enrutador::eliminarRuta(int posicion){
    vect::iterator pos;
    pos = conexiones.begin() + posicion;
    conexiones.erase(pos);
}

vect * Enrutador::retornarConexionesVecinas(){
    return &conexiones;
}

void Enrutador::mostrarConexionesVecinas(vector<string> letras){
    for (const auto &letra:letras){
        cout << letra << " ";
    }
    cout << endl;
    for (const auto i: conexiones){
        cout << i << " ";
    }
    cout << "\n\n";
}

void Enrutador::mostrarTabla(vector<string> letras){
    for (const auto &letra:letras){
        cout << letra << " ";
    }
    cout << endl;
    for (const auto i: tabla){
        cout << i << " ";
    }
    cout << "\n\n";
}

void Enrutador::setTablaEnrutamiento(TablaEnrutamiento tab){
    tabla = (*tab.getCaminos())[indice];            //Get caminos cortos
}

void Enrutador::pushBackConexionesTabla(){
    conexiones.push_back(0);
    tabla.push_back(0);
}



TablaEnrutamiento::TablaEnrutamiento(){
    for (int j = 0; j < 4; j++){
        vect temporal(4);
        for (int i = 0; i< 4;i++){
            temporal[i] = 0;
        }
        conexionesOrg.push_back(temporal);
        caminosCortos.push_back(temporal);
    }
    cantEnrutadores = 4;
}

void TablaEnrutamiento::pushBackConexiones(){
    vect temporal(conexionesOrg.size());
    for (int i = 0 ; i < int (temporal.size()); i++){
        temporal[i] = 0;
    }
    conexionesOrg.push_back(temporal);
    caminosCortos.push_back(temporal);
    for (auto &vect : conexionesOrg){
        vect.push_back(0);
    }
    for (auto &vect : caminosCortos){
        vect.push_back(0);
    }

}

vector<vect> * TablaEnrutamiento::getEnrutadores(){
    return &conexionesOrg;
}

vector<vect> * TablaEnrutamiento::getCaminos(){
    return &caminosCortos;
}

int TablaEnrutamiento::getCantEnrutadores(){
    return cantEnrutadores;
}

void TablaEnrutamiento::aumentarCantEnrutadores(){
    cantEnrutadores++;
}

void TablaEnrutamiento::setEnrutador(vect &conexiones,const int pos){
    int len = conexiones.size();
    for (int i = 0; i < len; i++){
        conexionesOrg[pos][i] = conexiones[i];
    }

}

void TablaEnrutamiento::eliminarEnrutador(int pos, vector<string> &letras){
    vect *elim = &conexionesOrg[pos],*elimCamino = &caminosCortos[pos];
    vect:: iterator borrar = (*elim).begin(),borrarCamino = (*elimCamino).begin();
    vector<string>::iterator letra = letras.begin()+ pos;
    letras.erase(letra);
    for (int i = 0; i < cantEnrutadores ; i++){
        (*elim).erase(borrar);
        (*elimCamino).erase(borrarCamino);
    }

    cantEnrutadores--;
    auto Elim = (conexionesOrg.begin()) + pos, ElimCamino = (caminosCortos.begin()) + pos;
    conexionesOrg.erase(Elim);
    caminosCortos.erase(ElimCamino);

    for (int i = 0; i < cantEnrutadores ; i++){
        elim = &conexionesOrg[i];
        elimCamino = &caminosCortos[i];
        borrar = (*elim).begin()+pos;
        borrarCamino = (*elimCamino).begin()+pos;
        (*elim).erase(borrar);
        (*elimCamino).erase(borrarCamino);
    }
}

void TablaEnrutamiento::mostrarEnrutadores(vector<string> letras){
    for (auto &letra: letras ){
        cout << "   " << letra;
    }
    vector<string> ::iterator iterador= letras.begin();
    for (const auto &caminoCorto: caminosCortos){
        cout << endl << *iterador << " ";
        *iterador ++;
        for (const auto  objeto: caminoCorto){
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
    vaciarCaminosCortos();
    for (int i = 0; i < cantEnrutadores; i++){
        dijkstra(conexionesOrg,i, caminosCortos);
    }
}


void actualizarTablas(TablaEnrutamiento tabla, vector <Enrutador *> &enrutadores){
    for (auto enrutador : enrutadores){
        (*enrutador).setTablaEnrutamiento(tabla);
    }
}

void TablaEnrutamiento::vaciarCaminosCortos(){
    for (int camino = 0; camino < int (caminosCortos.size()); camino++){
        for (int posicion = 0; posicion < int (caminosCortos[camino].size()); posicion++){
            caminosCortos[camino][posicion] = 0;
        }
    }

}




void menu(){
    vector <string> letras = {"A","B","C","D"};
    Enrutador A(0,"A"),B(1,"B"),C(2,"C"),D(3,"D"),A2, A3,A4,A5;
    vector  <Enrutador * > Enrutadores= {&A,&B,&C,&D}, restantes = {&A2,&A3,&A4,&A5};
    Enrutador *& punteroEnrut = restantes.back();

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
    //Establecer tablas de enrutamiento para cada enrutador
    rut.minDist();

    actualizarTablas(rut,Enrutadores);
    rut.mostrarEnrutadores(letras);
    int opcion = 0;


    while (opcion != 3){
        cout << "\nIngrese una opción."
                "\n1. Agregar enrutador."
                "\n2. Algo."
                "\n3 Salir."
                "\nOpcion: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            for(auto enrut : Enrutadores){
                enrut->pushBackConexionesTabla();
            }
            for(auto enrut : restantes){
                enrut->pushBackConexionesTabla();
            }
            punteroEnrut = restantes.back();
            agregar(&letras, &Enrutadores, *punteroEnrut);
            rut.pushBackConexiones();
            rut.setEnrutador(*punteroEnrut->retornarConexionesVecinas(),punteroEnrut->getIndex());
            Enrutadores.push_back(punteroEnrut);
            restantes.pop_back();
            rut.aumentarCantEnrutadores();
            rut.minDist();
            actualizarTablas(rut,Enrutadores);
            rut.mostrarEnrutadores(letras);
            cout << endl;
            for (auto enrutador : Enrutadores ){
                (*enrutador).mostrarTabla(letras);
            }

            break;
        case 2:

            break;
        case 3:
            system("cls");
            cout << "\nHasta pronto";
            break;
        default:
            cout << "\nOpción inválida.";
            break;
        }
    }


    /*
    Parte de implementación de borrar enrutador
    eliminar(&Enrutadores, &letras, &rut);
    rut.mostrarEnrutadores(letras);
    cout << endl;
    for (auto enrutador : Enrutadores ){
        (*enrutador).mostrarTabla(letras);
    }
    rut.minDist();
    actualizarTablas(rut,Enrutadores);



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

void eliminar(vector<Enrutador *> *Enrutadores, vector<string> *letras, TablaEnrutamiento *rut){
    vector <Enrutador *>:: iterator iteradorEnrut = (*Enrutadores).begin();
    bool validacion = false ;
    string ingresado;
    (*rut).mostrarEnrutadores(*letras);
    while (validacion != true){
        cout << "\nIngrese el nombre del enrutador que desea eliminar: ";
        cin >> ingresado;
        for (auto enrutador : (*Enrutadores)){
            if ((*enrutador).getId() == ingresado){
                validacion = true;
                (*rut).eliminarEnrutador((*enrutador).getIndex(),*letras);
                (*Enrutadores).erase(iteradorEnrut+(*enrutador).getIndex());
                (*rut).minDist();
                for (auto router : (*Enrutadores)){
                    if(router->getIndex()>=(*enrutador).getIndex()){
                        router->setIndex(router->getIndex()-1);
                        (*router).setTablaEnrutamiento(*rut);
                    }
                    else
                        (*router).setTablaEnrutamiento(*rut);
                }
                break;
            }
            if (validacion == false) system("cls");
        }
        /*
                    rut.mostrarEnrutadores(letras);
                    cout << endl;
                    for (auto enrutador : Enrutadores ){
                        (*enrutador).mostrarTabla(letras);
                    }
*/
        if (validacion != true)
            cout << "\nEnrutador no encontrado";
    }
}

void agregar(vector<string> *letras, vector<Enrutador *> *Enrutadores, Enrutador &punteroEnrut){
    string id;
    vector <Enrutador *>:: iterator iteradorEnrut = (*Enrutadores).begin();
    Enrutador * punteroDestino;
    cout <<"\nIngrese el nombre del enrutador: ";
    cin >> id;
    punteroEnrut.setIndex(Enrutadores->size());
    punteroEnrut.setId(id);
    for(const auto &letra:*letras){
        int costo;
        cout <<"\nIngrese el costo al enrutador " << letra << "\nEn "
        "caso de que no tenga conexión directa ingrese 0 \nCosto: ";
        cin >> costo;
        punteroEnrut.agregarRuta((*iteradorEnrut)->getIndex(),costo);      //Agregar el costo de la ruta directa para ese enrutador
        if(costo > 0){
            try {
                punteroDestino = Enrutadores->at((*iteradorEnrut)->getIndex());
                punteroDestino->agregarRuta(punteroEnrut.getIndex(),costo);
            } catch (const exception &) {
                cout << "\nSigue";
            }
        }
        iteradorEnrut++;
    }
    punteroEnrut.agregarRuta((punteroEnrut.getIndex()),0);
    (letras)->push_back(id);
}
