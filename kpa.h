#ifndef __KPA_H__
#define __KPA_H__

#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
#include "inversa.h"
#include <cstddef>

void multiplicar(size_t n, T1 A[10][10], T1 B[10][10], T1 C[10][10]);

void LlenarMatrix(size_t n, T1 inicio, T1 Cnum[200], T1 P[10][10], T1 C[10][10]);
T1 BuscadorBloques(T1 n, T1 numBloques,T1 Pnum[200], T1 Cnum[200]);
bool CalcularLlave(size_t n, T1 P[10][10],T1 C[10][10], T1 Pinversa[10][10], T1 K[10][10]);
void PrintLllave();
void DemoKPA();


#endif