#ifndef __CIFRADO__
#define __CIFRADO__
#include "tipos.h"
#include "descifrado.h"
#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

class Matrixllave
{
private:
    T1 **m_pMat = nullptr;
    size_t filas = 0;
    size_t columnas = 0;

public:
    Matrixllave() {}
    ~Matrixllave() { DestroyllaveMatrix(); }

    void CreatellaveMatrix();
    void DestroyllaveMatrix();

    void ReadllaveMatrix();
    void PrintllaveMatrix();
    void llaveMatrix(ostream &salida, istream &entrada);

    T1 Particion(size_t n, string mensaje, T1 mensajeNum[200]);

    void MCifrado(size_t n, size_t total, Convertidor &CO);
    
    friend class VInvertiblidad;
    friend class Convertidor;
};

// Convertidor
class Convertidor
{
private:
    T1 *m_mensaje = nullptr;
    size_t fila = 0;
    void Cambio_A(string mensaje);
    void Cambio_a(string mensaje);


public:
    Convertidor() {}
    ~Convertidor() { DeleteVectorMensaje(); }

    void numeroLetra(T1 *mensajeCifrado, size_t total);
    void letraNumero(string mensaje);
   
    void CreateVectorMensaje(size_t n);
    void TransfVectorMensaje(string mensaje);
    void PrintVectorMensaje(size_t n, size_t total);
    void DeleteVectorMensaje();

    friend class Matrixllave;
};

#endif // __CIFRADO__