#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Definición de la estructura de la tabla de enrutamiento
struct TablaEnrutamiento {
    map<string, string> rutas;

    void agregarRuta(const string& destino, const string& siguienteSalto) {
        rutas[destino] = siguienteSalto;
    }

    void eliminarRuta(const string& destino) {
        if (rutas.find(destino) != rutas.end()) {
            rutas.erase(destino);
        }
    }

    string encontrarSiguienteSalto(const string& destino) {
        if (rutas.find(destino) != rutas.end()) {
            return rutas[destino];
        } else {
            return "No se encontró una ruta para el destino";
        }
    }
};

// Clase Enrutador
class Enrutador {

private:
    vector<map<char,int>> conexionesVecinas;
    TablaEnrutamiento tablaEnrutamiento;

public:
    Enrutador();




    void configurarTablaDeEnrutamiento(const TablaEnrutamiento& tabla) {
        tablaEnrutamiento = tabla;
    }

    TablaEnrutamiento obtenerTablaDeEnrutamiento() {
        return tablaEnrutamiento;
    }

    void setConexiones(const vector<map<char, int> > &newConexiones);

    vector<map<char, int> > getConexiones() const;
};






int main() {
    Enrutador enrutador;
    TablaEnrutamiento tabla;

    tabla.agregarRuta("192.168.1.0", "192.168.0.1");
    tabla.agregarRuta("10.0.0.0", "10.0.0.1");

    enrutador.configurarTablaDeEnrutamiento(tabla);

    TablaEnrutamiento tablaObtenida = enrutador.obtenerTablaDeEnrutamiento();

    cout << "Tabla de enrutamiento del enrutador:" << endl;
    for (const auto& ruta : tablaObtenida.rutas) {
        cout << "Destino: " << ruta.first << " -> Siguiente salto: " << ruta.second << endl;
    }

    string siguienteSalto = tablaObtenida.encontrarSiguienteSalto("192.168.1.0");
    cout << "Siguiente salto para 192.168.1.0: " << siguienteSalto << endl;

    siguienteSalto = tablaObtenida.encontrarSiguienteSalto("8.8.8.8");
    cout << "Siguiente salto para 8.8.8.8: " << siguienteSalto << endl;

    return 0;
}






vector<map<char, int> > Enrutador::getConexiones() const
{
    return conexionesVecinas;
}

void Enrutador::setConexiones(const vector<map<char, int> > &newConexiones)
{
    conexionesVecinas = newConexiones;
}

Enrutador::Enrutador(){}
