#ifndef __CIFRADO__
#define __CIFRADO__
#include "tipos.h"
#include "descifrado.h"
#include <cstddef>
#include <string>
#include <iostream>
using namespace std;
// Convertidor
class Convertidor
{
private:
    T1 *m_mensaje = nullptr;
    size_t n ;
    void Cambio_A(string mensaje);
    void Cambio_a(string mensaje);


public:
    Convertidor() {}
    ~Convertidor() { DeleteVectorMensaje(); }

    T1 Particion(size_t n, string mensaje, T1* mensajeNum);
    void numeroLetra(T1 *mensajeCifrado, size_t total);
    void letraNumero(string mensaje);
   
    void CreateVectorMensaje(size_t n);
    T1 TransfVectorMensaje(size_t n,string mensaje, T1* mensajeNum);
    void PrintVectorMensaje(size_t n, size_t total);
    void DeleteVectorMensaje();

    void MensajeVector(string mensaje, T1 &total,  size_t n, ostream &salida, istream &entrada, T1* mensajeNum);

    friend class Matrixllave;
};


class Matrixllave
{
private:
    T1 **m_pMat = nullptr;
    size_t n = 0;


public:
    Matrixllave() {}
    ~Matrixllave() { DestroyllaveMatrix(); }

    void CreatellaveMatrix();
    void DestroyllaveMatrix();
    void ReadllaveMatrix();
    void PrintllaveMatrix();
    
    void llaveMatrix(ostream &salida, istream &entrada);

    

    void MCifrado(size_t n, T1 total, Convertidor &CO);

    friend void DemoCifradoHill();
};



#endif 