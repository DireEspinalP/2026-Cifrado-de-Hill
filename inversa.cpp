#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
#include "inversa.h"
#include <iostream>
#include <cstddef>

void Inversa::CambioFilas(size_t n, T1 aumentM[10][20], size_t i, size_t r)
{
    for (size_t j = 0; j < 2 * n; j++)
    {
        T1 aux = aumentM[i][j];
        aumentM[i][j] = aumentM[r][j];
        aumentM[r][j] = aux;
    }
}

void Inversa::CreatematrixAument(size_t n, T1 llave[10][10], T1 aumentM[10][20])
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < 2 * n; j++)
        {
            aumentM[i][j] = 0;
            for (size_t j = 0; j < n; j++)
            {
                aumentM[i][j] = ((llave[i][j] % 26) + 26) % 26;
                aumentM[i][j + n] = (i == j) ? 1 : 0;
            }
        }
    }
}
T1 Inversa::inversoMod26(T1 pivote)
{
    pivote = ((pivote % 26) + 26) % 26;
    for (T1 p = 1; p < 26; p++)
    {
        if ((pivote * p) % 26 == 1)
        {
            return p;
        }
    }
    return -1;
}
void Inversa::ElimGJ(size_t n, T1 aumentM[10][20], size_t i)
{
    for (size_t k = 0; k < n; k++)
    {
        if (k != i)
        {
            T1 factor = aumentM[k][i];
            for (size_t j = 0; j < 2 * n; j++)
            {
                aumentM[k][j] = ((aumentM[k][j] - factor * aumentM[i][j]) % 26 + 26) % 26;
            }
        }
    }
}

void Inversa::CreateInversa(size_t n, T1 aumentM[10][20], T1 inversa[10][10])
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            inversa[i][j] = aumentM[i][j + n];
        }
    }
}

void Inversa::normalizarFila(size_t n, T1 aumentaM[10][20], size_t i, T1 inv)
{
    for (size_t j = 0; j < 2 * n; j++)
    {
        aumentaM[i][j] = ((aumentaM[i][j] * inv) % 26 + 26) % 26;
    }
}

bool Inversa::Pivote(size_t n, T1 aumentaM[10][20], size_t i)
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

bool Inversa::InversaMatrix(size_t n, T1 llave[10][10], T1 Inv[10][10])
{
    T1 aumentM[10][20];
    CreatematrixAument(n, llave, aumentM);
    for (size_t i = 0; i < n; i++)
    {
        if (!Pivote(n, aumentM, i))
        {
            return false;
        }
        T1 inv = inversoMod26(aumentM[i][i]);
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
