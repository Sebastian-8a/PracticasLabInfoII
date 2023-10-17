#include "funciones.h"

void leer(vector<string> &datos){
    ifstream archivo;
    try {
        archivo.open("Conexiones.txt", ios::in);
        if (!archivo.is_open()){
            throw 1;
        }
    } catch (int num) {
        if (num == 1){
            cout << "\nFalla al abrir el archivo\n";
            return;
        }

    }

    while(!archivo.eof()){
        string temp;
        getline(archivo,temp,'\n');
        datos.push_back(temp);
    }
    archivo.close();
}






void Enrutador::agregarRuta(const char enrutador, const int costo ){
    conexionesVecinas[enrutador] = costo;
}

void Enrutador::eliminarRuta(const char enrutador){
    conexionesVecinas.erase(enrutador);
}

void Enrutador::mostrarCosto(char enrutador){
    try{
        cout << endl << conexionesVecinas.at(enrutador);
    }catch(const exception &e){
        cout << endl<< "No se ha encontrado el enrutador";
        return;
    }
}



Enrutador::Enrutador(){}

