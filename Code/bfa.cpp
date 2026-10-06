#include "bfa.h"
#include "cifrado.h"
#include "descifrado.h"
#include "inversa.h"
#include "tipos.h"
#include <iostream>
#include <string>

using namespace std;

void DemoBFA()
{
    BFA<T1> B;

    cout << "Tamano de la matriz llave a atacar (solo se soporta n = 2): ";
    size_t n;
    cin >> n;

    B.OrdendeAtaque(n);
}