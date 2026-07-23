#ifndef __DESCIFRADO_H__
#define __DESCIFRADO_H__
#include "tipos.h"
#include "cifrado.h"
#include <cstddef>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

template <typename T>
class VInvertiblidad{
    public:
T Determinante(size_t n, T** llave);
T det1x1(size_t n, T** llave);
T det2x2(size_t n, T** llave);
T detnxn(size_t n, T** llave);
T gcd(T a, T b);

bool esInvertibleMod26(T det);
};


void DemoCifradoHill();




template <typename T>
T VInvertiblidad<T>::det1x1(size_t n, T **llave)
{
    return ((llave[0][0] % 26 + 26) % 26);
}
template <typename T>
T VInvertiblidad<T>::det2x2(size_t n, T **llave)
{
    T valor = ((llave[0][0] * llave[1][1] - llave[0][1] * llave[1][0]) % 26);
    return (valor < 0) ? valor + 26 : valor;
}
template <typename T>
T VInvertiblidad<T>::detnxn(size_t n, T **llave)
{
    T det = 0;
    T **sub = new T *[n - 1];

    for (size_t i = 0; i < n - 1; i++)
    {
        sub[i] = new T[n - 1];
    }

    for (size_t x = 0; x < n; x++)
    {
        size_t subi = 0;
        for (size_t i = 1; i < n; i++)
        {
            size_t subj = 0;
            for (size_t j = 0; j < n; j++)
            {
                if (j == x)
                    continue;
                sub[subi][subj] = llave[i][j];
                subj++;
            }
            subi++;
        }
        auto signo = (x % 2 == 0) ? 1 : -1;
        det += signo * llave[0][x] * detnxn(n - 1, sub);
        det %= 26;
    }
    for (size_t i = 0; i < n - 1; i++)
    {
        delete[] sub[i];
    }

    delete[] sub;
    return (det < 0) ? det + 26 : det;
}
template <typename T>
T VInvertiblidad<T>::Determinante(size_t n, T **llave)
{
    T (VInvertiblidad<T>::*determinant[3])(size_t n, T **) = {det1x1, det2x2, detnxn};
      size_t ope = (n > 1) + (n > 2);
    return (this->*determinant[ope])(n, llave);
}
template <typename T>
T VInvertiblidad<T>::gcd(T a, T b)
{
    a = (a < 0) ? -a : a;
    for (; b != 0;)
    {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
template <typename T>
bool VInvertiblidad<T>::esInvertibleMod26(T det)
{
    det = ((det % 26) + 26) % 26;
    return gcd(det, 26) == 1;
}



#endif 