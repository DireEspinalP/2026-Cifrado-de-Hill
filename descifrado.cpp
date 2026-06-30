#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
#include <iostream>
#include <cstddef>
#include <string>
using namespace std;

// Verificamos la invertiblidad de la llave
// Solo para orden 2
T1 VInvertiblidad::det1x1(size_t n, T1 **llave)
{
    return ((llave[0][0] % 26 + 26) % 26);
}
T1 VInvertiblidad::det2x2(size_t n, T1 **llave)
{
    T1 valor = ((llave[0][0] * llave[1][1] - llave[0][1] * llave[1][0]) % 26);
    return (valor < 0) ? valor + 26 : valor;
}

T1 VInvertiblidad::detnxn(size_t n, T1 **llave)
{
    T1 det = 0;
    T1 **sub = new T1 *[n - 1];

    for (size_t i = 0; i < n - 1; i++)
    {
        sub[i] = new T1[n - 1];
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

T1 VInvertiblidad::Determinante(size_t n, T1 **llave)
{
    T1 (VInvertiblidad::*determinant[3])(size_t n, T1 **) = {det1x1, det2x2, detnxn};
      size_t ope = (n > 1) + (n > 2);
    return (this->*determinant[ope])(n, llave);
}

T1 VInvertiblidad::gcd(T1 a, T1 b)
{
    a = (a < 0) ? -a : a;
    for (; b != 0;)
    {
        T1 temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool VInvertiblidad::esInvertibleMod26(T1 det)
{
    det = ((det % 26) + 26) % 26;
    return gcd(det, 26) == 1;
}

void Convertidor::MensajeVector(string mensaje, T1 &total, size_t n, ostream &salida, istream &entrada, T1 *mensajeNum)
{
    salida << "Ingrese el mensaje a cifrar: ";
    salida << mensaje;
    getline(entrada, mensaje);
    CreateVectorMensaje(n);
    total = TransfVectorMensaje(n, mensaje, mensajeNum);
    PrintVectorMensaje(n, total);
}


void DemoCifradoHill()
{
    Matrixllave M;
    VInvertiblidad V;
    Convertidor CO;

    ostream &salida = cout;
    istream &entrada = cin;
   
    string mensaje;
    T1 *mensajeNum = nullptr;
    T1 total = 0;

    salida << "PRIMERO INGRESE LA LLAVE PARA CIFRAR EL MENSAJE " << endl;
    salida << "en el archivo 'llave_matriz.txt' : " << endl;

    salida << endl;
    M.llaveMatrix(salida, entrada);
    size_t n=M.n;

    V.esInvertibleMod26(V.Determinante(n, M.m_pMat)) ? salida << "La llave es invertible. Procediendo con el cifrado..." << endl
                                                     : salida << "La llave NO ES INVERTIBLE. Por favor, ingrese una llave válida." << endl;
    entrada.ignore();
    CO.MensajeVector(mensaje, total, n, salida, entrada, mensajeNum);
    M.MCifrado(n, total, CO);

    salida<<"Observa en el archivo 'mensaje_descifrado' tu mensaje esta cifrado...";


    CO.DeleteVectorMensaje();
    M.DestroyllaveMatrix();
}