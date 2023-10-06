#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void menu();

void ejercicio1();
void ejercicio2();


string decimalBinario(int caracter);
string leer();
void modificar(string contenido);
string contenidoEnBinario(string contenido);
string bloqueMet1(int cantUnos, int cantCeros, string bloque);
string bloqueMet2(string bloque);
string bloqueDecodifMet2(string bloqueCodif);


#endif // FUNCIONES_H
