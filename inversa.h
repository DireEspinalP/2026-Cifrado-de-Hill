#ifndef __INVERSA_H__
#define __INVERSA_H__

#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
class Inversa{
    public:
void CambioFilas(size_t n, T1 aumentM[10][20], size_t i, size_t r);

void CreatematrixAument(size_t n, T1 llave[10][10],T1 aumentM[10][20]);
bool Pivote(size_t n, T1 aumentM[10][20], size_t i);
T1 inversoMod26(T1 pivote);
void ElimGJ(size_t n, T1 aumentM[10][20], size_t i);

void CreateInversa(size_t n, T1 aumentM[10][20], T1 inversa[10][10]);
void normalizarFila(size_t n, T1 aumentaM[10][20], size_t i, T1 inv);

bool InversaMatrix(size_t n,  T1 llave[10][10], T1 Inv[10][10]);
};
#endif