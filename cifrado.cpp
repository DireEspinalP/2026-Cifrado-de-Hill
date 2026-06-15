#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>
#include <string>
#include <cstddef>
#include "tipos.h"
#include "cifrado.h"
using namespace std;

void EscribirllaveMatrix(size_t n, T1 llave[10][10]){
  ofstream outFile("llave_matriz.txt");
    for (size_t i=0; i<n; i++){
        for (size_t j=0; j<0; j++){
            outFile<<llave[i][j]<<" ";
        }
        outFile<<endl;
    }
    outFile.close();
}
void LeerllaveMatrix(size_t n, T1 llave[10][10]){
      ifstream inFile("llave_matriz.txt");
    for (size_t i=0; i<n; i++){
        for (size_t j=0; j<n; j++){
            inFile>>llave[i][j];
        }
    }
    inFile.close();
}

//Letra a num
void Cambio_A(string mensaje , T1 mensajeNum[200]){
    for (size_t i=0; i<mensaje.length(); i++){
        (mensaje[i]>='A' &&  mensaje[i] <= 'Z')? mensajeNum[i]=mensaje[i]- 'A': mensajeNum[i]=23;
    }
}

void Cambio_a(string mensaje,T1 mensajeNum[200]){
    for (size_t i=0; i<mensaje.length(); i++){
      (mensaje[i]>='a' &&  mensaje[i] <= 'z')?  mensajeNum[i]=mensaje[i]- 'a': mensajeNum[i]=23;
    }
    }

void letraNumero(string mensaje, T1 mensajeNum[200], size_t ope){
    void (*palabra[2])(string, T1[200])={Cambio_A, Cambio_a};
    {
            palabra[ope](mensaje, mensajeNum);
   }
}






void DemoCifrado(){
    cout<<"Escribe la llave de la matriz";
    T1 n=0;
    T1 llave[10][10];
    EscribirllaveMatrix(n, llave);
    LeerllaveMatrix(n, llave);
}