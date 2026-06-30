#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
#include "inversa.h"
#include "kpa.h"

#include <iostream>
#include <cstddef>
#include <fstream>
#include <string>

using namespace std;
// template <typename T1>
// void KPA<T1>::NewMemoriaKPA(size_t n, size_t longText)
// {
//   this->n = n;
//     Pnum = new T1[longText];
//     Cnum = new T1[longText];

//     P = new T1*[n];
//     for (size_t i = 0; i < n; i++) P[i] = new T1[n];

//     K = new T1*[n];
//     for (size_t i = 0; i < n; i++) K[i] = new T1[n];

//     C = new T1*[n];
//     for (size_t i = 0; i < n; i++) C[i] = new T1[n];

// }
// template <typename T1>
// void KPA<T1>::DeleteMemoriaKPA()
// {

//     if (P != nullptr)
//     {
//         for (size_t i = 0; i < n; i++)
//             delete[] P[i];
//         delete[] P;
//         P = nullptr;
//     }
//     if (K != nullptr)
//     {
//         for (size_t i = 0; i < n; i++)
//             delete[] K[i];
//         delete[] K;
//         K = nullptr;
//     }
//     if (C != nullptr)
//     {
//         for (size_t i = 0; i < n; i++)
//             delete[] C[i];
//         delete[] C;
//         C = nullptr;
//     }
//     delete[] Pnum;
//     Pnum = nullptr;
//     delete[] Cnum;
//     Cnum = nullptr;
// }
// template <typename T1>
// void KPA<T1>::multiplicar(size_t n, T1 **A, T1 **B, T1 **C)
// {
//     for (size_t i = 0; i < n; i++)
//     {
//         for (size_t j = 0; j < n; j++)
//         {
//             C[i][j] = 0;
//             for (size_t k = 0; k < n; k++)
//             {
//                 C[i][j] += A[i][k] * B[k][j];
//             }
//             C[i][j] = ((C[i][j] % 26) + 26) % 26;
//         }
//     }
// }
// template <typename T1>
// void KPA<T1>::LlenarMatrix(size_t n, T1 inicioB, T1 *Pnum, T1 *Cnum, T1 **P, T1 **C)
// {
//     for (size_t colum = 0; colum < n; colum++)
//     {
//         for (size_t fila = 0; fila < n; fila++)
//         {
//             T1 z = (inicioB + colum) * n + fila;
//             P[fila][colum] = Pnum[z];
//             C[fila][colum] = Cnum[z];
//         }
//     }
// }
// template <typename T1>
// T1 KPA<T1>::BuscadorBloques(size_t n, size_t numBloques, T1 *Pnum, T1 *Cnum, T1 **P, T1 **C)
// {
//     VInvertiblidad<VT> V;
//     for (size_t a = 0; a <= numBloques - n*n; a++)
//     {
//         LlenarMatrix(n, a, Pnum, Cnum, P, C);
//         if (V.esInvertibleMod26(V.Determinante(n, P)))
//         {
//             return a;
//         }
//     }
//     return -1;
// }
// template <typename T1>
// bool KPA<T1>::CalcularLlave(size_t n, T1 **P, T1 **C, T1 **Pinversa, T1 **K)
// {
//     Inversa<IT> I;
//     I.NewMemoriaI(n);
//     if (!I.InversaMatrix(n, P, Pinversa))
//     {
//         return false;
//     }

//     multiplicar(n, C, Pinversa, K);
//     return true;
// }
// template <typename T1>
// void KPA<T1>::PrintLllave(size_t n, T1 bloqueinicial, T1 **K)
// {
//     ofstream outFile("mensaje_descifrado");
//     outFile << "Llave descubierta" << endl;
//     for (size_t i = 0; i < n; i++)
//     {
//         for (size_t j = 0; j < n; j++)
//         {
//             outFile << K[i][j] << " ";
//         }
//         outFile << endl;
//     }
// }
// template <typename T1>
// void KPA<T1>::ConvertirText(string &plano, string &textocifrado)
// {
//     Convertidor<CT> COplano, COcifrado;

//     COplano.CreateVectorMensaje(plano.length());
//     COplano.letraNumero(plano);

//     COcifrado.CreateVectorMensaje(textocifrado.length());
//     COcifrado.letraNumero(textocifrado);
//     for (size_t i = 0; i < plano.length(); i++)
//         Pnum[i] = COplano.m_mensaje[i];

//     for (size_t i = 0; i < textocifrado.length(); i++)
//         Cnum[i] = COcifrado.m_mensaje[i];
// }
// template <typename T1>
// void KPA<T1>::NewPinversa()
// {
//     Pinversa = new T1 *[n];
//     for (size_t i = 0; i < n; i++)
//     {
//         Pinversa[i] = new T1[n];
//     }
// }
// template <typename T1>
// void KPA<T1>::Deleteinversa()
// {
//     if (Pinversa != nullptr)
//     {
//         for (size_t i = 0; i < n; i++)
//             delete[] Pinversa[i];

//         delete[] Pinversa;
//         Pinversa = nullptr;
//     }
// }

void DemoKPA()
{

    Inversa <T1> I;
    KPA <T1>Kpa;
    Convertidor <T1> COcifrado, COplano;

    ostream &salida = cout;
    istream &entrada = cin;
    size_t n;

    string plano, textocifrado;

    salida << "Tamano de la matrix: ";
    entrada >> n;
    Kpa.n = n;
    salida << "Texto plano: ";
    entrada >> plano;
    salida << "Texto cifrado: ";
    entrada >> textocifrado;


    Kpa.NewMemoriaKPA(n, plano.length());
    I.NewMemoriaI(n);
    Kpa.ConvertirText(plano, textocifrado);

    size_t numBloques = plano.length();
    T1 bloqueinicial = Kpa.BuscadorBloques(n, numBloques, Kpa.Pnum, Kpa.Cnum, Kpa.P, Kpa.C);
    Kpa.NewPinversa();
    if (!Kpa.CalcularLlave(n, Kpa.P, Kpa.C, Kpa.Pinversa, Kpa.K))
    {
        ofstream outFile("mensaje_descifrado");
        outFile << "No se pudo calcular la llave (P no es invertible)";
    }
    else
    {
        Kpa.PrintLllave(n, bloqueinicial, Kpa.K);
    }

    Kpa.Deleteinversa();
    Kpa.DeleteMemoriaKPA();
    I.DeleteMemoriaI();
}