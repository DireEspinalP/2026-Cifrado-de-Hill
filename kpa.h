#ifndef __KPA_H__
#define __KPA_H__

#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
#include "inversa.h"
#include <cstddef>
class KPA
{
public:
    T1 **P = nullptr;
    T1 **K = nullptr;
    T1 **C = nullptr;
    T1 *Pnum=nullptr;
    T1 *Cnum=nullptr;
    T1 **Pinversa=nullptr;
    size_t n;

    KPA(){}
    ~KPA(){DeleteMemoriaKPA(); Deleteinversa();}

    void NewMemoriaKPA(size_t n,size_t longText);
    void DeleteMemoriaKPA();

    void multiplicar(size_t n, T1** A, T1** B, T1** C);
    void LlenarMatrix(size_t n, T1 inicioB, T1* Pnum, T1* Cnum, T1** P, T1** C);
    T1 BuscadorBloques(size_t n, size_t numBloques, T1* Pnum, T1* Cnum, T1** P, T1** C);
    bool CalcularLlave(size_t n, T1** P, T1** C, T1** Pinversa, T1** K);
    void PrintLllave(size_t n, T1 bloqueinicial, T1** K);

    void ConvertirText(string &plano, string &textocifrado);
    void NewPinversa();
    void Deleteinversa();

    friend class Matrixllave;
    

};
 void DemoKPA();
#endif