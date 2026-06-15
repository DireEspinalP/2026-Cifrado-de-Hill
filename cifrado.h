#ifndef __CIFRADO__
#define __CIFRADO__
#include "tipos.h"
#include <cstddef>
#include <string>

void leerllaveMatrix(size_t n,T1 llave[10][10]);
void EscribirllaveMatrix(size_t n, T1 llave[10][10]);
void llaveMatrix(string mensaje, T1 mensajeNum[200], size_t ope);

void DemoCifrado();


#endif