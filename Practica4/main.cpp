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



void dijkstra(vector<vector<int>> &vectores, int src)
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
    for (int i = 0; i < len; i++){
        vectores[src][i] = dist[i];
    }
    printSolution(dist,len);
}



int main(){
    vector<char> letras = {'A','B','C','D'};
    Enrutador A(0,'A'),B(1,'B'),C(2,'C'),D(3,'D');
    TablaEnrutamiento rut;
    A.agregarRuta(B.getIndex(),4); A.agregarRuta(C.getIndex(),10);
    B.agregarRuta(A.getIndex(),4); B.agregarRuta(D.getIndex(),1);
    C.agregarRuta(A.getIndex(),10); C.agregarRuta(D.getIndex(),2);
    D.agregarRuta(C.getIndex(),2); D.agregarRuta(B.getIndex(),1);




    rut.setEnrutador(*A.retornarConexionesVecinas(),A.getIndex());
    rut.setEnrutador(*B.retornarConexionesVecinas(),B.getIndex());
    rut.setEnrutador(*C.retornarConexionesVecinas(),C.getIndex());
    rut.setEnrutador(*D.retornarConexionesVecinas(),D.getIndex());

    rut.mostrarEnrutadores(letras);
    rut.eliminarEnrutador(B.getIndex());
    letras.erase(letras.begin()+1);
    rut.mostrarEnrutadores(letras);

    //dijkstra(*rut.getEnrutadores(),0);
    cout << endl;
    return 0;
}

/*
    A.mostrarConexionesVecinas(letras);
    A.eliminarRuta(1);
    letras.erase(letras.begin()+1);
    A.mostrarConexionesVecinas(letras);





    vector<int> vector1 = { 0 , 4 , 10 , 0 };
    vector<int> vector2 = { 4 , 0 , 0 , 1 };
    vector<int> vector3 = { 10 , 0 , 0 , 2 };
    vector<int> vector4 = { 0 , 1 , 2 , 0 };
    vector<vector<int>> vectores = {vector1, vector2,vector3,vector4};


    dijkstra(vectores, 0);



*/

