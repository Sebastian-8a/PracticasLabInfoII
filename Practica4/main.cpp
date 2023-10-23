#include <iostream>
#include <limits.h>
#include "funciones.h"

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])  //shortest path tree set
{


    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(vector<vector<int>> vectores, int src)
{
    int dist[V]; // The output array.  dist[i] will hold the
        // shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is
        // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && vectores[u][v]
                && dist[u] != INT_MAX
                && dist[u] + vectores[u][v] < dist[v])
                dist[v] = dist[u] + vectores[u][v];
    }

    // print the constructed distance array
    printSolution(dist);
}

// driver's code
int main()
{
    vector<int> vector1 = { 0, 4, 0, 0, 0, 0, 0, 8, 0 };
    vector<int> vector2 = { 4, 0, 8, 0, 0, 0, 0, 11, 0 };
    vector<int> vector3 = { 0, 8, 0, 7, 0, 4, 0, 0, 2 };
    vector<int> vector4 = { 0, 0, 7, 0, 9, 14, 0, 0, 0 };
    vector<int> vector5 = { 0, 0, 0, 9, 0, 10, 0, 0, 0 };
    vector<int> vector6 = { 0, 0, 4, 14, 10, 0, 2, 0, 0 };
    vector<int> vector7 = { 0, 0, 0, 0, 0, 2, 0, 1, 6 };
    vector<int> vector8 = { 8, 11, 0, 0, 0, 0, 1, 0, 7 };
    vector<int> vector9 = { 0, 0, 2, 0, 0, 0, 6, 7, 0 };
    vector<vector<int>> vectores = {vector1, vector2,vector3,vector4,vector5,vector6,vector7,vector8,vector9};
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                       { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                       { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                       { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                       { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                       { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                       { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                       { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                       { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    // Function call
    dijkstra(vectores, 0);

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

    rut.setEnrutador(A.retornarConexionesVecinas());
    rut.setEnrutador(B.retornarConexionesVecinas());
    rut.setEnrutador(C.retornarConexionesVecinas());
    rut.setEnrutador(D.retornarConexionesVecinas());


    rut.mostrarEnrutadores();







    //A.mostrarCosto('B');
    //A.eliminarRuta('B');
    //A.mostrarCosto('B');

    //cout << endl << A.getAt('B');




    return 0;
}
*/

