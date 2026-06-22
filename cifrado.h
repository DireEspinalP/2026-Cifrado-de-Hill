#ifndef __CIFRADO__
#define __CIFRADO__
#include "tipos.h"
#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

void LeerllaveMatrix(size_t n,T1 llave[10][10]);
void EscribirllaveMatrix(size_t n, T1 llave[10][10]);
void llaveMatrix(size_t n, T1 llave[10][10], ostream &salida, istream &entrada);

//Convertidor
void numeroLetra(T1 mensajeNum[200], string &mensaje, size_t longitud);
void letraNumero(string mensaje, T1 mensajeNum[200], size_t ope);
void Cambio_A(string mensaje, T1 mensajeNum[200]);
void Cambio_a(string mensaje, T1 mensajeNum[200]);


T1 Particion(size_t n, string mensaje, T1 mensajeNum[200]);
T1 CrearMensajeNum(size_t n, string mensaje, T1 mensajeNum[200]);
void PrintMatrixmensajeNum(size_t n, size_t total, T1 mensajeNum[]);

void MCifrado(size_t n, T1 llave[10][10], T1 mensajeNum[200], size_t total, T1 mensajeCifrado[200]);



#endif // __CIFRADO__