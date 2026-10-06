#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
#include "inversa.h"
#include "kpa.h"

#include <iostream>
#include <cstddef>
#include <fstream>
#include <string>

using namespace std;

void DemoKPA()
{

    Inversa <T1> I;
    KPA <T1>Kpa;
    Convertidor <T1> COcifrado, COplano;

    ostream &salida = cout;
    istream &entrada = cin;
    size_t n;

    string plano, textocifrado;

    salida << "Tamano de la matrix: ";
    entrada >> n;
    Kpa.n = n;
    salida << "Texto plano: ";
    entrada >> plano;
    salida << "Texto cifrado: ";
    entrada >> textocifrado;


    Kpa.NewMemoriaKPA(n, plano.length());
    I.NewMemoriaI(n);
    Kpa.ConvertirText(plano, textocifrado);

    size_t numBloques = plano.length();
    T1 bloqueinicial = Kpa.BuscadorBloques(n, numBloques, Kpa.Pnum, Kpa.Cnum, Kpa.P, Kpa.C);
    Kpa.NewPinversa();
    if (!Kpa.CalcularLlave(n, Kpa.P, Kpa.C, Kpa.Pinversa, Kpa.K))
    {
        ofstream outFile("mensaje_descifrado");
        outFile << "No se pudo calcular la llave (P no es invertible)";
    }
    else
    {
        Kpa.PrintLllave(n, bloqueinicial, Kpa.K);
    }

    Kpa.Deleteinversa();
    Kpa.DeleteMemoriaKPA();
    I.DeleteMemoriaI();
}