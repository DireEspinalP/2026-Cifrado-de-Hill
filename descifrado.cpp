#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
#include <iostream>
#include <cstddef>
#include <string>
using namespace std;

// Verificamos la invertiblidad de la llave
// Solo para orden 2

T1 Determinante(size_t n, T1 llave[10][10])
{
    size_t ope=0;
    T1 (*determinant[3])(size_t n, T1[10][10]) = {det1x1, det2x2, detnxn};

    return determinant[ope](n, llave);
}
T1 det1x1(size_t n, T1 llave[10][10])
{
    return ((llave[0][0] % 26 + 26) % 26);
}
T1 det2x2(size_t n, T1 llave[10][10])
{
    T1 valor = ((llave[0][0] * llave[1][1] - llave[0][1] * llave[1][0]) % 26);
    return (valor < 0) ? valor + 26 : valor;
}

T1 detnxn(size_t n, T1 llave[10][10])
{
    T1 det = 0;
    T1 sub[10][10];
 
  
    for (size_t x = 0; x < n; x++)
    {
         size_t subi = 0;
        for (size_t i = 1; i < n; i++)
        {  size_t subj = 0;
            for (size_t j = 0; j < n; j++)
            {
                if (j == x)
                    continue;
                sub[subi][subj] = llave[i][j];
                subj++;
            }
            subi++;
        }
        T1 signo = (x % 2 == 0) ? 1 : -1;
        det += signo * llave[0][x] * detnxn(n - 1, sub);
        det %= 26;
    }
    return (det < 0) ? det + 26 : det;
}


T1 gcd(T1 a, T1 b)
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



bool esInvertibleMod26(T1 det)
{
    det = ((det % 26) + 26) % 26;
    return gcd(det, 26) == 1;
}


void DemoCifradoHill()
{
    ostream &salida = cout;
    istream &entrada = cin;
    size_t n=0;
    string mensaje;

    T1 llave[10][10];
    T1 mensajeCifrado[200];
    T1 mensajeNum[200];
   

    salida << "PRIMERO INGRESE LA LLAVE PARA CIFRAR EL MENSAJE " << endl;  
    salida << "en el archivo 'llave_matriz.txt' : " << endl;
    salida<<endl;
    llaveMatrix(n, llave, salida, entrada);

    esInvertibleMod26(Determinante(n, llave)) ? salida << "La llave es invertible. Procediendo con el cifrado..." << endl
                                                   : salida << "La llave NO ES INVERTIBLE. Por favor, ingrese una llave válida." << endl;
    entrada.ignore();
   
    salida << "Ingrese el mensaje a cifrar: ";
    getline(entrada, mensaje);

     size_t total = CrearMensajeNum(n, mensaje, mensajeNum);
    MCifrado(n, llave, mensajeNum, total, mensajeCifrado);
    

    salida<<endl;
     salida<<"OBSERVE EN EL ARCHIVO 'mensaje_cifrado.txt"<<endl;
}