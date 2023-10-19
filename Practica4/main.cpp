#include "funciones.h"


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



    /*

    rut.setRuta((quote(A)),A.retornarConexionesVecinas());
    rut.setRuta((quote(B)),B.retornarConexionesVecinas());
    rut.setRuta((quote(C)),C.retornarConexionesVecinas());
    rut.setRuta((quote(D)),D.retornarConexionesVecinas());
    rut.mostrarRutas();



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


