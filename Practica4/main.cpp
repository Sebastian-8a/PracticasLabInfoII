#include <iostream>
#include <limits.h>
#include "funciones.h"

int minDistance(int dist[], bool sptSet[], int len)
{
    /*
    Analizar de las distancias cuál es la menor y que no haya sido procesada
    min: distancia más corta de los caminos que no han sido procesados
    */
    int min = INT_MAX, min_index;   // Inicializar valor mínimo como el número máximo, indicar que no ha sido procesado

    for (int v = 0; v < len; v++)
        if (sptSet[v] == false && dist[v] <= min)
            //Si: el camino no ha sido procesado y la distancia al enrutador v es menor a min
            min = dist[v], min_index = v;

    return min_index;
}



void printSolution(int dist[], int len)
{
    for (char letra = 'A'; letra < 'E'; letra++){
        cout << letra << " ";
    }
    cout << endl;
    for (int i = 0 ; i < len; i++)
        cout << dist[i] << " ";
}



void dijkstra(vector<vector<int>> vectores, int src)
{
    /*
    src: posición del enrutador al que le quiero calcular el camino más corto
    len:cantidad de enrutadores
    dist: almacen de distancias mínimas desde src a cada enrutador
    sptSet:shortest path tree set: arreglo que indica si se ha encontrado la distancia mínima a cada enrutador
    */
    int len = vectores.size();

    int dist[len];
    bool sptSet[len];
    for (int i = 0; i < len; i++)         //Inicializar todos los caminos como distancia máxima y vertice no procesado
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;          // La distancia del enrutador a si mismo es 0

    // Find shortest path for all vertices
    for (int count = 0; count < len - 1; count++) {

        int u = minDistance(dist, sptSet, len);         //camino mínimo del arreglo de distancias.
        //u en la primera iteración siempre es src
        //u: indice de la distancia más corta de los caminos que no han sido procesados

        sptSet[u] = true;       //el camino a u ha sido procesado

        for (int v = 0; v < len; v++)
            if (!sptSet[v] && vectores[u][v]        //sptSet[v] es false, cumple
                && dist[u] != INT_MAX
                && dist[u] + vectores[u][v] < dist[v])
                //la distancia que tiene almacenada más el enrutador
                //en la posición U con el enrutador a evaluar V es menor
                //a la distancia que se tiene en V
                dist[v] = dist[u] + vectores[u][v];
    }
}



int main()
{
    vector<int> vector1 = { 0 , 4 , 10 , 0 };
    vector<int> vector2 = { 4 , 0 , 0 , 1 };
    vector<int> vector3 = { 10 , 0 , 0 , 2 };
    vector<int> vector4 = { 0 , 1 , 2 , 0 };

    vector<vector<int>> vectores = {vector1, vector2,vector3,vector4};


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

