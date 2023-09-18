#include "zonapruebas.h"

void ZonaPruebas()
{
    ;
}



int conversionCharInt(char arreglo[], int cantNums){
    int unidad = 1;
    int num = 0;
    for (int j = 1; j<= cantNums ; j++){
        unidad *= 10;
    }
    for(int i = cantNums; i>0; i--){
        num += arreglo[i]*unidad;
        unidad /= 10;
    }
    return 0;
}




