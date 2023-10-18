#include "funciones.h"
#define quote(x) #x         //Macro

int main() {
    tablaEnrutamiento rut;
    Enrutador A, B, C, D;
    A.agregarRuta('B',4); A.agregarRuta('C',10);A.agregarRuta('A',0);
    B.agregarRuta('A',4); B.agregarRuta('D',1);B.agregarRuta('B',0);
    C.agregarRuta('A',10);C.agregarRuta('D',2);C.agregarRuta('C',0);
    D.agregarRuta('C',2);D.agregarRuta('B',1);D.agregarRuta('D',0);


    rut.setRuta(quote(A),A.retornarConexionesVecinas());
    rut.setRuta(quote(B),B.retornarConexionesVecinas());
    rut.setRuta(quote(C),C.retornarConexionesVecinas());
    rut.setRuta(quote(D),D.retornarConexionesVecinas());
    rut.mostrarRutas();








    /*




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


