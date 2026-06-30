#ifndef __DESCIFRADO_H__
#define __DESCIFRADO_H__
#include "tipos.h"
#include <cstddef>

class VInvertiblidad{
    public:
T1 Determinante(size_t n, T1** llave);
T1 det1x1(size_t n, T1** llave);
T1 det2x2(size_t n, T1** llave);
T1 detnxn(size_t n, T1** llave);
T1 gcd(T1 a, T1 b);

bool esInvertibleMod26(T1 det);
};



void DemoCifradoHill();


#endif 