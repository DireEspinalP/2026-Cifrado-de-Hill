#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>
#include <string>
#include <cstddef>
#include "tipos.h"
#include "cifrado.h"
using namespace std;

void  Matrixllave::EscribirllaveMatrix(size_t n, T1 llave[10][10])
{
    ofstream outFile("llave_matriz.txt");
    outFile<<"La llave de la matrix es: "<<endl;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            outFile << llave[i][j] << " ";
        }
        outFile << endl;
    }
    outFile<<"verificacion";
    outFile.close();
}
void Matrixllave::LeerllaveMatrix(size_t n, T1 llave[10][10])
{
    ifstream inFile("llave_matriz.txt");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            inFile >> llave[i][j];
        }
    }
    inFile.close();
}

// Letra a num
void Convertidor::Cambio_A(string mensaje, T1 mensajeNum[200])
{
    for (size_t i = 0; i < mensaje.length(); i++)
    {
        (mensaje[i] >= 'A' && mensaje[i] <= 'Z') ? mensajeNum[i] = mensaje[i] - 'A' : mensajeNum[i] = 23;
    }
}

void Convertidor::Cambio_a(string mensaje, T1 mensajeNum[200])
{
    for (size_t i = 0; i < mensaje.length(); i++)
    {
        (mensaje[i] >= 'a' && mensaje[i] <= 'z') ? mensajeNum[i] = mensaje[i] - 'a' : mensajeNum[i] = 23;
    }
}

void Convertidor::letraNumero(string mensaje, T1 mensajeNum[200])
{
   size_t ope=0;
    void (Convertidor::*palabra[2])(string, T1[200]) = {Cambio_A, Cambio_a};
    
    {
        
      (this->*palabra[ope])(mensaje, mensajeNum);
    }
}

void Convertidor::numeroLetra(T1 mensajeCifrado[200], size_t total){
    ofstream outFile("mensaje_cifrado.txt");
    outFile<<"El mensaje cifrado es : "<<endl;
    for (size_t i = 0; i < total; i++)
    {
        outFile << T3(mensajeCifrado[i] + 'A');
    }
    outFile << endl;
    outFile.close();
}

T1 Matrixllave::Particion(size_t n, string mensaje, T1 mensajeNum[200])
{
    size_t longitud = (size_t)mensaje.length();
    size_t padding = (n - (longitud % n)) % n;
    for (size_t i = 0; i < padding; i++)
    {
        mensajeNum[longitud + i] = 23;
    }
    return longitud + padding;
}

T1 Matrixllave::CrearMensajeNum(size_t n, string mensaje, T1 mensajeNum[200])
{
    Convertidor CO;
    CO.letraNumero(mensaje, mensajeNum);
    return Particion(n, mensaje, mensajeNum);
}

void Matrixllave::PrintMatrixMensaje(size_t n, size_t total, T1 mensajeNum[])
{
    ofstream outFile("mensaje_cifrado.txt");
    auto k = total / n;
   
    for (size_t i = 0; i <k; i++)
    {
        for (size_t j = 0 ; j < n; j++)
        {
            outFile << mensajeNum[i * n + j] << " ";
        }
        outFile << endl;
    }
    
    outFile.close();
}

void Matrixllave::MCifrado(size_t n, T1 llave[10][10], T1 mensajeNum[200], size_t total, T1 mensajeCifrado[200])
{
    Convertidor CO;
    ofstream cipherFile("mensaje_cifrado.txt");
    auto k = total / n;
    for (size_t i = 0; i < k; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            mensajeCifrado[i * n + j] = 0;
            for (size_t l = 0; l < n; l++)
            {
                mensajeCifrado[i * n + j] += llave[j][l] * mensajeNum[i * n + l];
            }
            mensajeCifrado[i * n + j] = ((mensajeCifrado[i * n + j] % 26) + 26) % 26;
        }
    }
    cipherFile << "Mensaje cifrado es:" << endl;
    CO.numeroLetra(mensajeCifrado, total);
    cipherFile.close();
}

void Matrixllave::llaveMatrix(size_t& n, T1 llave[10][10], ostream &salida, istream &entrada)
{
   salida<<"Eliga el numero de orden de la matrix llave :";
   entrada>>n;
    LeerllaveMatrix(n, llave);
    salida << endl;
    EscribirllaveMatrix(n, llave);
}