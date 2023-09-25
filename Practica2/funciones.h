#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string.h>
#include <map>
#include <string>

using namespace std;


void ejercicio2();
void problema2();
void problema4();
void problema6();
void problema8();
void problema10();
void problema12();
void problema14();
void problema16();
void problema18();

void fun_c(double *, int, double *, double *);
void aleatorio(char[],int);
void contar(char [], int , int [] );
int conversionCharInt(string );
string minusAMayus(string);
string texto(string , int *);
int romanoArabigo(string );
bool cuadradoMagico(int **, int);        //modifico el 3 con base en el tamaño de la matriz
int ** rotar(int **);
int factorial(int );
int caminosPosibles(int );




#endif // FUNCIONES_H
