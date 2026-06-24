#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
#include "inversa.h"
#include <iostream>
#include <cstddef> 


void multiplicar(size_t n, T1 A[10][10], T1 B[10][10], T1 C[10][10]){
    for (size_t i=0; i<n; i++){
        for (size_t j=0; j<n; j++){
            C[i][j]=0;
            for (size_t k=0; k<n; k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
            C[i][j]=((C[i][j]%26)+26)%26;
        }
    }
}

void LlenarMatrix(size_t n, T1 inicioB, T1 Pnum[200], T1 Cnum[200], T1 P[10][10], T1 C[10][10]){
    for(size_t colum=0; colum<n; colum++){
        for (size_t fila=0; fila<n; fila++){
            T1 z=(inicioB+colum)*n+fila; 
            P[fila][colum]=Pnum[z];
            C[fila][colum]=Cnum[z];

         }
    }

}
T1 BuscadorBloques(size_t n, T1 numBloques,T1 Pnum[200], T1 Cnum[200], T1 P[10][10], T1 C[10][10])
{
    for (T1 a=0; a<= numBloques-(T1)n ; a++){
        LlenarMatrix(n,a,Pnum,Cnum,P ,C);
        if (esInvertibleMod26(Determinante(n,P))){
            return a;
        }
    }
return -1;
}

bool CalcularLlave(size_t n, T1 P[10][10],T1 C[10][10], T1 Pinversa[10][10], T1 K[10][10]){
    if(!InversaMatrix(n,P,Pinversa)){ return false;}

    multiplicar(n,C,Pinversa,K);
    return true;
}
void PrintLllave(ostream& salida , T1 n, T1 bloqueinicial, T1 K[10][10]){
    salida<<"Llave descubierta"<<endl;
    for (size_t i=0; i<n; i++){
        for (size_t j=0; j<n; j++){
            salida<<K[i][j]<<" ";
        }
        salida<<endl;
    }
}
void DemoKPA();