#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>
#include <string>
#include <cstddef>

#include "tipos.h"
#include "cifrado.h"

using namespace std;

void Matrixllave::CreatellaveMatrix(){
    m_pMat=new T1*[n];
    for (size_t i=0; i<n; i++){
        m_pMat[i]=new T1[n];
    }
}

void Matrixllave::ReadllaveMatrix(){
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

void  Matrixllave::PrintllaveMatrix(){
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


void Matrixllave::DestroyllaveMatrix(){
    if(m_pMat==nullptr) return ;
    for (size_t i=0; i<n; i++){
        delete[] m_pMat[i];
    }
    delete[] m_pMat;
    m_pMat=nullptr;

}

T1 Convertidor::Particion(size_t n, string mensaje, T1* mensajeNum)
{
    
    size_t longitud = mensaje.length();
    size_t padding = (n - (longitud % n)) % n;
    for (size_t i = 0; i < padding; i++)
    {
        mensajeNum[longitud + i] = 23;
    }
    return longitud + padding;
}


void Matrixllave::llaveMatrix( ostream &salida, istream &entrada)
{
   salida<<"Eliga el numero de orden de la matrix llave :";
   entrada>>this->n;
    CreatellaveMatrix();
    ReadllaveMatrix();
    salida << endl;
    PrintllaveMatrix();
}

void Matrixllave::MCifrado(size_t n, T1 total, Convertidor &CO)
{
    T1* mensajeCifrado=new T1[total];
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
void Convertidor::Cambio_A(string mensaje)
{
    for (size_t i = 0; i < mensaje.length(); i++)
    {
        (mensaje[i] >= 'A' && mensaje[i] <= 'Z') ? m_mensaje[i] = mensaje[i] - 'A' : m_mensaje[i] = 23;
    }
}

void Convertidor::Cambio_a(string mensaje)
{
    for (size_t i = 0; i < mensaje.length(); i++)
    {
        (mensaje[i] >= 'a' && mensaje[i] <= 'z') ? m_mensaje[i] = mensaje[i] - 'a' : m_mensaje[i] = 23;
    }
}

void Convertidor::letraNumero(string mensaje)
{
    
    void (Convertidor::*palabra[2])(string) = {Cambio_A, Cambio_a};

    {
     size_t ope = (mensaje[0] >> 5) & 1;
     (  this->*palabra[ope])(mensaje);
    }
}

void Convertidor::numeroLetra(T1* mensajeCifrado, size_t total){
    ofstream outFile("mensaje_cifrado.txt");
    outFile<<"El mensaje cifrado es : "<<endl;
    for (size_t i = 0; i < total; i++)
    {
        outFile << T3(mensajeCifrado[i] + 'A');
    }
    outFile << endl;
    outFile.close();
}



void Convertidor::CreateVectorMensaje(size_t total){ 
    m_mensaje=new T1[total];
}

T1 Convertidor::TransfVectorMensaje(size_t n, string mensaje, T1*mensajeNum)
{
     T1 total=Particion(n, mensaje, mensajeNum);
     letraNumero(mensaje);
     size_t longitud = mensaje.length();
     for (size_t i=longitud; i < (size_t)total; i++){
        m_mensaje[i]=26;
        
     }
     return total;
}


void Convertidor::PrintVectorMensaje(size_t n, size_t total)
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

void Convertidor::DeleteVectorMensaje(){
    if(m_mensaje!=nullptr){
        delete[] m_mensaje;
        m_mensaje = nullptr;
    }
}



