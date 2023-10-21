#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include "funciones.h"




// Función para encontrar el camino más corto utilizando el algoritmo de Dijkstra
void dijkstra(vector<Router>& graph, int start) {
    /*

    connection: to y weight
    Router: Vector de conexiones
    graph: Vector de routers
    n : cantidad de enrutadores
    distance: vector de enteros: diastancias a todos los nodos
    processed: vector de booleanos: estado de procesamiento de cada camino
    pq: Cola de prioridad los elementos se almacenan sedgún su orden de prioridad, orden descendente
    u: elemento que se encuentra como el mayor en pq y segundo elemento del par
    start:Enrutador al que le quiero encontrar los caminos más cortos

    */
    int n = graph.size();
    vector<int> distance(n, INF); // Distancias iniciales a todos los nodos como infinito
    vector<bool> processed(n, false);       //Vector de n elementos, todos falsos

    distance[start] = 0;        //la distancia a mi mismo es 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));           //Hacer un par de elementos y agregarlo a la cola

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (processed[u]) continue;
        processed[u] = true;

        for (const Connection& conn : graph[u].connections) {       //itera sobre las conexiones de U
            /*
            v: hacia quién me enlazo
            weight: costo del enlace
            */
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

    int start_node = 0;
    dijkstra(graph, start_node);

    return 0;
}


/*

int main() {
    TablaEnrutamiento rut;
    Enrutador A(quote(A)),B(quote(B)),C(quote(C)),D(quote(D));                  //4 enrutadores por defecto, en caso de desear más, se debe crear manualmente
    //list<Enrutador> enrutadores = {A,B,C,D};

    A.agregarRuta('B',4); A.agregarRuta('C',10);
    B.agregarRuta('A',4); B.agregarRuta('D',1);
    C.agregarRuta('A',10);C.agregarRuta('D',2);
    D.agregarRuta('C',2);D.agregarRuta('B',1);

    rut.setRuta(A.retornarConexionesVecinas());
    rut.setRuta(B.retornarConexionesVecinas());
    rut.setRuta(C.retornarConexionesVecinas());
    rut.setRuta(D.retornarConexionesVecinas());


    rut.mostrarRutas();







    //A.mostrarCosto('B');
    //A.eliminarRuta('B');
    //A.mostrarCosto('B');

    //cout << endl << A.getAt('B');




    return 0;
}
*/

