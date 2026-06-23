#ifndef __KPA_H__
#define __KPA_H__

#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
#include <cstddef>

void multiplicar(size_t n, T1 A[10][10], T1 B[10][10], T1 C[10][10]);

void LlenarMatrix();
void BuscadorBloques();
void CalcularLlave();
void PrintLllave();
void DemoKPA();


#endif