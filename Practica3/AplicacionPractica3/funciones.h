#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void menuInicial();


string decimalBinario(int caracter);
string leer(string nombreEntrada);
void modificar(string contenido);
string contenidoEnBinario(string contenido);
string bloqueMet1(int cantUnos, int cantCeros, string bloque);
string bloqueMet2(string bloque);
string bloqueDecodifMet2(string bloqueCodif);


#endif // FUNCIONES_H
