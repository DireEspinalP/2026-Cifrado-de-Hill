#ifndef __KPA_H__
#define __KPA_H__

#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
#include "inversa.h"
#include <cstddef>
#include <string>
#include <fstream>

template <typename T>
class KPA
{
public:
    T **P = nullptr;
    T **K = nullptr;
    T **C = nullptr;
    T *Pnum=nullptr;
    T *Cnum=nullptr;
    T **Pinversa=nullptr;
    size_t n;

    KPA(){}
    ~KPA(){DeleteMemoriaKPA(); Deleteinversa();}

    void NewMemoriaKPA(size_t n,size_t longText);
    void DeleteMemoriaKPA();

    void multiplicar(size_t n, T** A, T** B, T** C);
    void LlenarMatrix(size_t n, T inicioB, T* Pnum, T* Cnum, T** P, T** C);
    T BuscadorBloques(size_t n, size_t numBloques, T* Pnum, T* Cnum, T** P, T** C);
    bool CalcularLlave(size_t n, T** P, T** C, T** Pinversa, T** K);
    void PrintLllave(size_t n, T bloqueinicial, T** K);

    void ConvertirText(string &plano, string &textocifrado);
    void NewPinversa();
    void Deleteinversa();

    template <typename Q>
    friend class Matrixllave;
    

};
template <typename T>
void KPA<T>::NewMemoriaKPA(size_t n, size_t longText)
{
  this->n = n;
    Pnum = new T[longText];
    Cnum = new T[longText];

    P = new T*[n];
    for (size_t i = 0; i < n; i++) P[i] = new T[n];

    K = new T*[n];
    for (size_t i = 0; i < n; i++) K[i] = new T[n];

    C = new T*[n];
    for (size_t i = 0; i < n; i++) C[i] = new T[n];

}
template <typename T>
void KPA<T>::DeleteMemoriaKPA()
{

    if (P != nullptr)
    {
        for (size_t i = 0; i < n; i++)
            delete[] P[i];
        delete[] P;
        P = nullptr;
    }
    if (K != nullptr)
    {
        for (size_t i = 0; i < n; i++)
            delete[] K[i];
        delete[] K;
        K = nullptr;
    }
    if (C != nullptr)
    {
        for (size_t i = 0; i < n; i++)
            delete[] C[i];
        delete[] C;
        C = nullptr;
    }
    delete[] Pnum;
    Pnum = nullptr;
    delete[] Cnum;
    Cnum = nullptr;
}
template <typename T>
void KPA<T>::multiplicar(size_t n, T **A, T **B, T **C)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (size_t k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
            C[i][j] = ((C[i][j] % 26) + 26) % 26;
        }
    }
}
template <typename T>
void KPA<T>::LlenarMatrix(size_t n, T inicioB, T *Pnum, T *Cnum, T **P, T **C)
{
    for (size_t colum = 0; colum < n; colum++)
    {
        for (size_t fila = 0; fila < n; fila++)
        {
            T z = (inicioB + colum) * n + fila;
            P[fila][colum] = Pnum[z];
            C[fila][colum] = Cnum[z];
        }
    }
}
template <typename T>
T KPA<T>::BuscadorBloques(size_t n, size_t numBloques, T *Pnum, T *Cnum, T **P, T **C)
{
    VInvertiblidad<T> V;
    for (size_t a = 0; a <= numBloques - n*n; a++)
    {
        LlenarMatrix(n, a, Pnum, Cnum, P, C);
        if (V.esInvertibleMod26(V.Determinante(n, P)))
        {
            return a;
        }
    }
    return -1;
}
template <typename T>
bool KPA<T>::CalcularLlave(size_t n, T **P, T **C, T **Pinversa, T **K)
{
    Inversa<T> I;
    I.NewMemoriaI(n);
    if (!I.InversaMatrix(n, P, Pinversa))
    {
        return false;
    }

    multiplicar(n, C, Pinversa, K);
    return true;
}
template <typename T>
void KPA<T>::PrintLllave(size_t n, T bloqueinicial, T **K)
{
    ofstream outFile("mensaje_descifrado");
    outFile << "Llave descubierta" << endl;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            outFile << K[i][j] << " ";
        }
        outFile << endl;
    }
}
template <typename T>
void KPA<T>::ConvertirText(string &plano, string &textocifrado)
{
    Convertidor<T> COplano, COcifrado;

    COplano.CreateVectorMensaje(plano.length());
    COplano.letraNumero(plano);

    COcifrado.CreateVectorMensaje(textocifrado.length());
    COcifrado.letraNumero(textocifrado);
    for (size_t i = 0; i < plano.length(); i++)
        Pnum[i] = COplano.m_mensaje[i];

    for (size_t i = 0; i < textocifrado.length(); i++)
        Cnum[i] = COcifrado.m_mensaje[i];
}
template <typename T>
void KPA<T>::NewPinversa()
{
    Pinversa = new T *[n];
    for (size_t i = 0; i < n; i++)
    {
        Pinversa[i] = new T[n];
    }
}
template <typename T>
void KPA<T>::Deleteinversa()
{
    if (Pinversa != nullptr)
    {
        for (size_t i = 0; i < n; i++)
            delete[] Pinversa[i];

        delete[] Pinversa;
        Pinversa = nullptr;
    }
}
 void DemoKPA();
#endif