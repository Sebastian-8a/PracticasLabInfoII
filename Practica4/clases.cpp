#include "clases.h"


Enrutador::Enrutador(){
    indice = -1;
    id = "";
    conexiones.push_back(0);
    conexiones.push_back(0);
    conexiones.push_back(0);
    conexiones.push_back(0);
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

void Enrutador::setId(char identificador){
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

void Enrutador::mostrarConexionesVecinas(vector<char> letras){
    for (const auto letra:letras){
        cout << letra << " ";
    }
    cout << endl;
    for (const auto i: conexiones){
        cout << i << " ";
    }
    cout << "\n\n";
}

void Enrutador::mostrarTabla(vector<char> letras){
    for (const auto letra:letras){
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

vector<vect> * TablaEnrutamiento::getEnrutadores(){
    return &conexionesOrg;
}

vector<vect> * TablaEnrutamiento::getCaminos(){
    return &caminosCortos;
}

int TablaEnrutamiento::getCantEnrutadores(){
    return cantEnrutadores;
}

void TablaEnrutamiento::setEnrutador(vect &conexiones,const int pos){
    int len = conexiones.size();
    for (int i = 0; i < len; i++){
        conexionesOrg[pos][i] = conexiones[i];
    }

}

void TablaEnrutamiento::eliminarEnrutador(int pos, vector<char> &letras){
    vect *elim = &conexionesOrg[pos],*elimCamino = &caminosCortos[pos];
    vect:: iterator borrar = (*elim).begin(),borrarCamino = (*elimCamino).begin();
    vector<char>::iterator letra = letras.begin()+ pos;
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

void TablaEnrutamiento::mostrarEnrutadores(vector<char> letras){
    //vector<char> ::iterator iterador= letras.begin();
    for (auto letra: letras ){
        cout << "   " << letra;
    }
    vector<char> ::iterator iterador= letras.begin();
    for (const auto &i: caminosCortos){
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
        dijkstra(conexionesOrg,i, caminosCortos);
    }
}


void actualizarTablas(TablaEnrutamiento tabla, vector <Enrutador *> &enrutadores){
    for (auto enrutador : enrutadores){
        (*enrutador).setTablaEnrutamiento(tabla);
    }
}






void menu(){
    vector<char> letras = {'A','B','C','D'};
    Enrutador A(0,"A"),B(1,"B"),C(2,"C"),D(3,"D"),A2, A3,A4,A5;
    vector  <Enrutador * > Enrutadores= {&A,&B,&C,&D};
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

    int opcion = 0;

    while (opcion != 3){
        cout << "\nIngrese una opción."
                "\n1. Eliminar enrutador."
                "\n2. Algo."
                "\n3 Salir."
                "\nOpcion: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            eliminar(&Enrutadores, &letras, &rut);
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

void eliminar(vector<Enrutador *> *Enrutadores, vector<char> *letras, TablaEnrutamiento *rut){
    vector <Enrutador *>:: iterator iteradorEnrut = (*Enrutadores).begin();
    bool validacion = false ;
    string ingresado;
    iteradorEnrut = (*Enrutadores).begin();
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
