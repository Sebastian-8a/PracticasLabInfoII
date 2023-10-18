#include "funciones.h"
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX; // Valor para representar la distancia infinita

// Estructura para representar una conexión entre enrutadores
struct Connection {
    int to;      // Nodo de destino
    int weight;  // Peso de la conexión
    Connection(int t, int w) : to(t), weight(w) {}
};

// Estructura para representar un enrutador y sus conexiones
struct Router {
    vector<Connection> connections;
};

// Función para encontrar el camino más corto utilizando el algoritmo de Dijkstra
void dijkstra(vector<Router>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INF); // Distancias iniciales a todos los nodos como infinito
    vector<bool> processed(n, false);

    distance[start] = 0;

    priority_queue<pair<int, int>> pq; // Cola de prioridad para elegir el nodo con la distancia más corta
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (processed[u]) continue;
        processed[u] = true;

        for (const Connection& conn : graph[u].connections) {
            int v = conn.to;
            int weight = conn.weight;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push(make_pair(-distance[v], v));
            }
        }
    }

    // Imprimir las distancias mínimas desde el nodo de inicio a todos los nodos
    for (int i = 0; i < n; ++i) {
        cout << "Distancia mínima desde " << start << " a " << i << " = " << distance[i] << endl;
    }
}

int main() {
    int n = 5; // Número de enrutadores
    vector<Router> graph(n);

    // Definir las conexiones entre enrutadores
    graph[0].connections.push_back(Connection(1, 2));
    graph[0].connections.push_back(Connection(2, 4));
    graph[1].connections.push_back(Connection(2, 1));
    graph[1].connections.push_back(Connection(3, 7));
    graph[2].connections.push_back(Connection(3, 3));
    graph[3].connections.push_back(Connection(4, 1));

    int start_node = 0; // Nodo de inicio para encontrar el camino más corto
    dijkstra(graph, start_node);





    /*
    TablaEnrutamiento rut;
    Enrutador A, B, C, D;
    A.agregarRuta('B',4); A.agregarRuta('C',10);
    B.agregarRuta('A',4); B.agregarRuta('D',1);
    C.agregarRuta('A',10);C.agregarRuta('D',2);
    D.agregarRuta('C',2);D.agregarRuta('B',1);


    rut.setRuta(A.retornarConexionesVecinas());
    rut.setRuta(B.retornarConexionesVecinas());
    rut.setRuta(C.retornarConexionesVecinas());
    rut.setRuta(D.retornarConexionesVecinas());
    rut.mostrarRutas();




    A.mostrarCosto('B');
    A.eliminarRuta('B');
    A.mostrarCosto('B');
*/
    //cout << endl << A.getAt('B');




    return 0;
}


