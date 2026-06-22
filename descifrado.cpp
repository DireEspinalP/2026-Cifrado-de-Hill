#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
#include <iostream>
#include <cstddef>
#include <string>   
using namespace std;

//Verificamos la invertiblidad de la llave 
//Solo para orden 2 
T1 Determinante(size_t n, T1 llave[10][10]){
 T1 (*determinant[3])(size_t, T1[10][10]) = {det1x1, det2x2, detnxn};
    {
        determinant[n-1](n, llave);
    }

}
T1 det1x1(size_t n, T1 llave[10][10]){
    return ((llave[0][0]%26+26)%26);
}
T1 det2x2(size_t n, T1 llave[10][10]){
    T1 valor=((llave[0][0] * llave[1][1] - llave[0][1] * llave[1][0]) % 26);
    valor=(valor<0)? valor+26:valor;
    return valor;
}
T1 detnxn(size_t n, T1 llave[10][10], T1 sub[10][10]){
    T1 det=0;
    size_t subi=0;
    for (size_t x = 0; x < n; x++) {
        for (size_t i = 1; i < n; i++) {
            size_t subj = 0;
            for (size_t j = 0; j < n; j++) {
                if (j == x) continue;
                sub[subi][subj] = llave[i][j];
                subj++;
            }
            subi++;
        }
        T1 signo = (x % 2 == 0) ? 1 : -1;
        det += signo * llave[0][x] * detnxn(n - 1, sub);
        det %= 26;
    }
    if (det < 0) det += 26;
    return det;
      
}

T1 gcd(T1 a, T1 b) {
    a = (a < 0) ? -a : a; 
    for( ;b != 0; ) {
        T1 temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool esInvertibleMod26(T1 det) {
    det = ((det % 26) + 26) % 26;
    return gcd(det, 26) == 1;
}

void DemoCifradoHill(){
    ostream& salida=cout;
    istream& entrada=cin;
    T1 n;
    string mensaje;
     T1 mensajeNum[200]; 
    size_t total = CrearMensajeNum(n, mensaje, mensajeNum);
    T1 llave[10][10];
    T1 mensajeCifrado[200];
   

    salida << "Ingrese la llave para cifrar el mensaje: " << endl;
    llaveMatrix(n, llave ,salida,entrada);

    esInvertibleMod26(Determinante(n, llave)) ? salida << "La llave es invertible. Procediendo con el cifrado..." << endl
                                           : salida << "La llave no es invertible. Por favor, ingrese una llave válida." << endl;
    entrada.ignore();
    salida << "Ingrese el mensaje a cifrar: ";
    getline(entrada, mensaje);
    MCifrado(n, llave, mensajeNum,total, mensajeCifrado);
}