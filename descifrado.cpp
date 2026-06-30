#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
#include <iostream>
#include <cstddef>
#include <string>
using namespace std;


void DemoCifradoHill()
{
    Matrixllave<T1> M;
    VInvertiblidad<T1>  V;
    Convertidor<T1>  CO;

    ostream &salida = cout;
    istream &entrada = cin;
   
    string mensaje;
    T1 *mensajeNum = nullptr;
    T1 total = 0;

    salida << "PRIMERO INGRESE LA LLAVE PARA CIFRAR EL MENSAJE " << endl;
    salida << "en el archivo 'matriz_llave.txt' : " << endl;

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