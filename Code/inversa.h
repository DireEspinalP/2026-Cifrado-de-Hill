#ifndef __INVERSA_H__
#define __INVERSA_H__

#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"

template <typename T>
class Inversa
{
private:
    T **pmat = nullptr;
    T** aumentM=nullptr;
    T** inversa=nullptr;
    size_t n = 0;
public:

    Inversa() {}
    ~Inversa(){DeleteMemoriaI();}

    void NewMemoriaI(size_t n);
    void DeleteMemoriaI();

    void CambioFilas(size_t n, T** aumentM, size_t i, size_t r);
    void CreatematrixAument(size_t n, T**llave, T** aumentM);
    bool Pivote(size_t n, T** aumentM, size_t i);
    T inversoMod26(T pivote);
    void ElimGJ(size_t n, T** aumentM, size_t i);
    void CreateInversa(size_t n, T** aumentM, T** inversa);
    void normalizarFila(size_t n, T** aumentaM, size_t i, T inv);
    bool InversaMatrix(size_t n, T** llave,T** inv);

};


template<typename T>
void Inversa<T>::NewMemoriaI(size_t n)
{
    this->n=n;
    pmat = new T *[n];
    for (size_t i = 0; i < n; i++)
    {
        pmat[i] = new T[n];
    }
    inversa = new T *[n];
    for (size_t i = 0; i < n; i++)
    {
        inversa[i] = new T[n];
    }

    aumentM = new T *[n];
    for (size_t i = 0; i < n; i++)
    {
        aumentM[i] = new T[2*n];
    }
}
template<typename T>
void Inversa<T>::DeleteMemoriaI()
{
    if (pmat != nullptr) {
        for (size_t i = 0; i < n; i++) delete[] pmat[i];
        delete[] pmat;
        pmat = nullptr;
    }
    if (inversa != nullptr) {
        for (size_t i = 0; i < n; i++) delete[] inversa[i];
        delete[] inversa;
        inversa = nullptr;
    }
    if (aumentM != nullptr) {
        for (size_t i = 0; i < n; i++) delete[] aumentM[i];
        delete[] aumentM;
        aumentM = nullptr;
    }
}
template<typename T>
void Inversa<T>::CambioFilas(size_t n, T **aumentM, size_t i, size_t r)
{
    for (size_t j = 0; j < 2 * n; j++)
    {
        T aux = aumentM[i][j];
        aumentM[i][j] = aumentM[r][j];
        aumentM[r][j] = aux;
    }
}
template<typename T>
void Inversa<T>::CreatematrixAument(size_t n, T **llave, T **aumentM)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            aumentM[i][j] = ((llave[i][j] % 26) + 26) % 26;
            aumentM[i][j + n] = (i == j) ? 1 : 0;
        }
    }
}
template<typename T>
T Inversa<T>::inversoMod26(T pivote)
{
    pivote = ((pivote % 26) + 26) % 26;
    for (T p = 1; p < 26; p++)
    {
        if ((pivote * p) % 26 == 1)
        {
            return p;
        }
    }
    return -1;
}
template<typename T>
void Inversa<T>::ElimGJ(size_t n, T **aumentM, size_t i)
{
    for (size_t k = 0; k < n; k++)
    {
        if (k != i)
        {
            T factor = aumentM[k][i];
            for (size_t j = 0; j < 2 * n; j++)
            {
                aumentM[k][j] = ((aumentM[k][j] - factor * aumentM[i][j]) % 26 + 26) % 26;
            }
        }
    }
}
template<typename T>
void Inversa<T>::CreateInversa(size_t n, T **aumentM, T **inversa)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            inversa[i][j] = aumentM[i][j + n];
        }
    }
}
template<typename T>
void Inversa<T>::normalizarFila(size_t n, T **aumentaM, size_t i, T inv)
{
    for (size_t j = 0; j < 2 * n; j++)
    {
        aumentaM[i][j] = ((aumentaM[i][j] * inv) % 26 + 26) % 26;
    }
}
template<typename T>
bool Inversa<T>::Pivote(size_t n, T **aumentaM, size_t i)
{
    if (aumentaM[i][i] != 0)
        return true;

    for (size_t r = i + 1; r < n; r++)
    {
        if (aumentaM[r][i] != 0)
        {
            CambioFilas(n, aumentaM, i, r);
            return true;
        }
    }
    return false;
}
template <typename T>
bool Inversa<T>::InversaMatrix(size_t n, T **llave, T **Inv)
{

    CreatematrixAument(n, llave, aumentM);
    for (size_t i = 0; i < n; i++)
    {
        if (!Pivote(n, aumentM, i))
        {
            return false;
        }
        T inv = inversoMod26(aumentM[i][i]);
        if (inv == -1)
        {
            return false;
        }
        normalizarFila(n, aumentM, i, inv);
        ElimGJ(n, aumentM, i);
    }
    CreateInversa(n, aumentM, Inv);
    return true;
}

#endif