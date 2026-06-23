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

void LlenarMatrix();
void BuscadorBloques();
void CalcularLlave();
void PrintLllave();
void DemoKPA();