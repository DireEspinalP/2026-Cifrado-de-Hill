#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
#include <iostream>
#include <cstddef> 
#include <utility>

void CambioFilas(size_t n, T1 aumentM[10][20], size_t i, size_t r){
    for (size_t j=0; j<2*n; j++){
        T1 aux=aumentM[i][j];
        aumentM[i][j]=aumentM[r][j];
        aumentM[r][j]=aux;
    }
}

void CreatematrixAument(size_t n, T1 llave[10][10],T1 aumentM[10][20]){
    for (size_t i=0; i<n; i++){
        for (size_t j=0; j<n; j++){
            aumentM[i][j]=((llave[i][j]%26)+26)%26;
             aumentM[i][j + n] = (i == j) ? 1 : 0;
        }
    }

}
T1 inversoMod26(T1 pivote){

    for(T1 p=1; p<26 ; p++){
       if  ((pivote*p)%26==1){
        return p;
       }
    }
    return -1;

}
void ElimGJ(size_t n, T1 aumentM[10][20], size_t i){
    for (size_t k=0 ; k<n; k++){
        if(k!=i){
            T1 factor=aumentM[k][i];
            for (size_t j=0; j<2*n; j++){
                aumentM[k][j]=((aumentM[k][j]-factor*aumentM[i][j])%26+26)%26;
          }
        }
    }
}

void CreateInversa(size_t n, T1 aumentM[10][20], T1 inversa[10][10]){
    for (size_t i=0; i<n; i++){
        for (size_t j=0; j<n ; j++){
            inversa[i][j]=aumentM[i][j+n];
        }
    }

}

void normalizarFila(size_t n, T1 aumentaM[10][20], size_t i, T1 inv){
    for (size_t j=0; j<2*n; j++){
        aumentaM[i][j]=((aumentaM[i][j]*inv)%26+26)%26;
    }
}

bool Pivote(size_t n, T1 aumentaM[10][20], size_t i){
    if(aumentaM[i][i]!=0) return true;

    for (size_t r= i+1; r<n; r++){
        if (aumentaM[r][i]!=0){
            CambioFilas(n, aumentaM, i, r);
            return true; 

        }
    }
    return false;
}

