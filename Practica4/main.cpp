#include "funciones.h"


int main() {


    Enrutador A, B;
    A.agregarRuta('B',4); A.agregarRuta('C',10);
    TablaEnrutamiento rut;
    mapa mapita;
    mapita['B'] = 4;
    rut.setRuta(mapita);
    rut.mostrarRutas();



    /*
    A.mostrarCosto('B');
    A.eliminarRuta('B');
    A.mostrarCosto('B');
*/
    //cout << endl << A.getAt('B');

    return 0;
}







