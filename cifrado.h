#ifndef __CIFRADO__
#define __CIFRADO__
#include "tipos.h"
#include "descifrado.h"
#include <cstddef>
#include <string>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// Convertidor
template <typename T>
class Convertidor
{
private:
    T *m_mensaje = nullptr;
    size_t n;
    void Cambio_A(string mensaje);
    void Cambio_a(string mensaje);

public:
    Convertidor() {}
    ~Convertidor() { DeleteVectorMensaje(); }

    T Particion(size_t n, string mensaje, T *mensajeNum);
    void numeroLetra(T *mensajeCifrado, size_t total);
    void letraNumero(string mensaje);

    void CreateVectorMensaje(size_t n);
    T TransfVectorMensaje(size_t n, string mensaje, T *mensajeNum);
    void PrintVectorMensaje(size_t n, size_t total);
    void DeleteVectorMensaje();

    void MensajeVector(string mensaje, T &total, size_t n, ostream &salida, istream &entrada, T *mensajeNum);

    template <typename Q>
    friend class Matrixllave;
    template <typename Q>
    friend class KPA;
};

template <typename T>
class Matrixllave
{
private:
    T **m_pMat = nullptr;
    size_t n = 0;

public:
    Matrixllave() {}
    ~Matrixllave() { DestroyllaveMatrix(); }

    void CreatellaveMatrix();
    void DestroyllaveMatrix();
    void ReadllaveMatrix();
    void PrintllaveMatrix();

    void llaveMatrix(ostream &salida, istream &entrada);

    void MCifrado(size_t n, T total, Convertidor<T> &CO);

   
    friend void DemoCifradoHill();
    friend void DemoKPA();
};


template <typename T>
void Matrixllave<T>::CreatellaveMatrix(){
    m_pMat=new T*[n];
    for (size_t i=0; i<n; i++){
        m_pMat[i]=new T[n];
    }
}
template<typename T>
void Matrixllave<T>::ReadllaveMatrix(){
    ifstream inFile("matriz_llave.txt");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            inFile >> m_pMat[i][j];
        }
        
    }
    inFile.close();
}
template<typename T>
void  Matrixllave<T>::PrintllaveMatrix(){
    ofstream outFile("matriz_llave.txt");
    outFile<<"La llave de la matrix es: "<<endl;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            outFile << m_pMat[i][j]<< " ";
        }
        outFile << endl;
    }
    outFile.close();
}

template<typename T>
void Matrixllave<T>::DestroyllaveMatrix(){
    if(m_pMat==nullptr) return ;
    for (size_t i=0; i<n; i++){
        delete[] m_pMat[i];
    }
    delete[] m_pMat;
    m_pMat=nullptr;

}
template<typename T>
T Convertidor<T>::Particion(size_t n, string mensaje, T* mensajeNum)
{
    
    size_t longitud = mensaje.length();
    size_t padding = (n - (longitud % n)) % n;
    for (size_t i = 0; i < padding; i++)
    {
        mensajeNum[longitud + i] = 23;
    }
    return longitud + padding;
}

template<typename T>
void Matrixllave<T>::llaveMatrix( ostream &salida, istream &entrada)
{
   salida<<"Eliga el numero de orden de la matrix llave :";
   entrada>>this->n;
    CreatellaveMatrix();
    ReadllaveMatrix();
    salida << endl;
    PrintllaveMatrix();
}
template<typename T>
void Matrixllave<T>::MCifrado(size_t n, T total, Convertidor<T> &CO)
{
    T* mensajeCifrado=new T[total];
    auto k = total / n;
    for (size_t i = 0; i < k; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            mensajeCifrado[i * n + j] = 0;
            for (size_t l = 0; l < n; l++)
            {
                mensajeCifrado[i * n + j] += m_pMat[j][l] * CO.m_mensaje[i * n + l];
            }
            mensajeCifrado[i * n + j] = ((mensajeCifrado[i * n + j] % 26) + 26) % 26;
        }
    }
   CO.numeroLetra(mensajeCifrado,total);
   delete[] mensajeCifrado;
}



// Letra a num
template<typename T>
void Convertidor<T>::Cambio_A(string mensaje)
{
    for (size_t i = 0; i < mensaje.length(); i++)
    {
        (mensaje[i] >= 'A' && mensaje[i] <= 'Z') ? m_mensaje[i] = mensaje[i] - 'A' : m_mensaje[i] = 23;
    }
}

template<typename T>
void Convertidor<T>::Cambio_a(string mensaje)
{
    for (size_t i = 0; i < mensaje.length(); i++)
    {
        (mensaje[i] >= 'a' && mensaje[i] <= 'z') ? m_mensaje[i] = mensaje[i] - 'a' : m_mensaje[i] = 23;
    }
}
template<typename T>
void Convertidor<T>::letraNumero(string mensaje)
{
    size_t ope =0;
    void (Convertidor::*palabra[2])(string) = {Cambio_A, Cambio_a};

    {
     (  this->*palabra[ope])(mensaje);
    }
}
template<typename T>
void Convertidor<T>::numeroLetra(T* mensajeCifrado, size_t total){
    ofstream outFile("mensaje_cifrado.txt");
    outFile<<"El mensaje cifrado es : "<<endl;
    for (size_t i = 0; i < total; i++)
    {
        outFile << T3(mensajeCifrado[i] + 'A');
    }
    outFile << endl;
    outFile.close();
}


template<typename T>
void Convertidor<T>::CreateVectorMensaje(size_t total){ 
    m_mensaje=new T[total];
}
template<typename T>
T Convertidor<T>::TransfVectorMensaje(size_t n, string mensaje, T*mensajeNum)
{
     T total=Particion(n, mensaje, mensajeNum);
     letraNumero(mensaje);
     size_t longitud = mensaje.length();
     for (size_t i=longitud; i < (size_t)total; i++){
        m_mensaje[i]=26;
        
     }
     return total;
}

template<typename T>
void Convertidor<T>::PrintVectorMensaje(size_t n, size_t total)
{
    ofstream outFile("mensaje_cifrado.txt");
    auto k = total / n;
   
    for (size_t i = 0; i <k; i++)
    {
        for (size_t j = 0 ; j < n; j++)
        {
            outFile << m_mensaje[i * n + j] << " ";
        }
        outFile << endl;
    }
    
    outFile.close();
}
template<typename T>
void Convertidor<T>::DeleteVectorMensaje(){
    if(m_mensaje!=nullptr){
        delete[] m_mensaje;
        m_mensaje = nullptr;
    }
}

template <typename T>
void Convertidor<T>::MensajeVector(string mensaje, T &total, size_t n, ostream &salida, istream &entrada, T *mensajeNum)
{
    salida << "Ingrese el mensaje a cifrar: ";
    salida << mensaje;
    getline(entrada, mensaje);
    CreateVectorMensaje(n);
    total = TransfVectorMensaje(n, mensaje, mensajeNum);
    PrintVectorMensaje(n, total);
}


#endif