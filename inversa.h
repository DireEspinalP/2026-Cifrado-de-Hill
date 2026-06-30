#ifndef __INVERSA_H__
#define __INVERSA_H__

#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
class Inversa
{
private:
    T1 **pmat = nullptr;
    T1** aumentM=nullptr;
    T1** inversa=nullptr;
    size_t n = 0;
public:

    Inversa() {}
    ~Inversa(){DeleteMemoriaI();}

    void NewMemoriaI(size_t n);
    void DeleteMemoriaI();

    void CambioFilas(size_t n, T1** aumentM, size_t i, size_t r);
    void CreatematrixAument(size_t n, T1**llave, T1** aumentM);
    bool Pivote(size_t n, T1** aumentM, size_t i);
    T1 inversoMod26(T1 pivote);
    void ElimGJ(size_t n, T1** aumentM, size_t i);
    void CreateInversa(size_t n, T1** aumentM, T1** inversa);
    void normalizarFila(size_t n, T1** aumentaM, size_t i, T1 inv);
    bool InversaMatrix(size_t n, T1** llave,T1** inv);

};


#endif