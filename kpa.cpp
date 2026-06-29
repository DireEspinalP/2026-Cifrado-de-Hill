// #include "cifrado.h"
// #include "descifrado.h"
// #include "tipos.h"
// #include "inversa.h"

// #include <iostream>
// #include <cstddef>
// #include <fstream>
// #include <string>

// using namespace std;

// void multiplicar(size_t n, T1 A[10][10], T1 B[10][10], T1 C[10][10])
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

// void LlenarMatrix(size_t n, T1 inicioB, T1 Pnum[200], T1 Cnum[200], T1 P[10][10], T1 C[10][10])
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
// T1 BuscadorBloques(size_t n, size_t numBloques, T1 Pnum[200], T1 Cnum[200], T1 P[10][10], T1 C[10][10])
// {
//     VInvertiblidad V;
//     for (size_t a = 0; a <= numBloques - n; a++)
//     {
//         LlenarMatrix(n, a, Pnum, Cnum, P, C);
//         if (V.esInvertibleMod26(V.Determinante(n, P)))
//         {
//             return a;
//         }
//     }
//     return -1;
// }

// bool CalcularLlave(size_t n, T1 P[10][10], T1 C[10][10], T1 Pinversa[10][10], T1 K[10][10])
// {
//     Inversa I;
//     if (!I.InversaMatrix(n, P, Pinversa))
//     {
//         return false;
//     }

//     multiplicar(n, C, Pinversa, K);
//     return true;
// }
// void PrintLllave( size_t n, T1 bloqueinicial, T1 K[10][10])
// {
//     ofstream outFile("mensaje_descifrado");
//     outFile << "Llave descubierta" << endl;
//     for (size_t i = 0; i < n; i++)
//     {
//         for (size_t j = 0; j < n; j++)
//         {
//             outFile << K[i][j] << " ";
//         }
//        outFile << endl;
//     }
// }

// void DemoKPA()
// {
//     Convertidor CO;

//     ofstream outFile("mensaje_descifrado");
//     ostream &salida= cout;
//     istream &entrada = cin;

//     string plano, textocifrado;
//     size_t n;
//     T1 Pnum[200], Cnum[200];

//     salida << "Tamano de la matrix: ";
//     entrada >> n;

//     salida << "Texto plano: ";
//     entrada >> plano;
//     salida << "Texto cifrado: ";
//     entrada >> textocifrado;

//     salida << endl; 
//     size_t numBloques = size_t(plano.length() / n);

//     CO.letraNumero(plano, Pnum);
//     CO.letraNumero(textocifrado, Cnum);

//     T1 P[10][10], C[10][10], K[10][10], Pinversa[10][10];

//     T1 bloqueinicial = BuscadorBloques(n, numBloques, Pnum, Cnum, P, C);

//     if (bloqueinicial == -1)
//     {
//         outFile << "No se encontro un bloque de la llave en mod26";
//         return;
//     }

//     if (!CalcularLlave(n, P, C, Pinversa, K))
//     {
//         outFile << "No se pudo calcular la llave (P no es invertible)";
//         return;
//     }

//     outFile << endl;

//     PrintLllave(n, bloqueinicial, K);
// }
