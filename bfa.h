#ifndef __BFA_H__
#define __BFA_H__
#include <string>
#include <iostream>
#include "tipos.h"
#include "cifrado.h"
#include "descifrado.h"
#include "inversa.h"
using namespace std;

template <typename T>
class BFA
{
public:
    T *Cnum = nullptr;
    T **K = nullptr;
    T **Pinversa = nullptr;
    size_t n;

    BFA();
    ~BFA(){ DeleteMemoriaBFA(); }

    void NewMemoriaBFA(size_t longText);
    void DeleteMemoriaBFA();


    void ConvertirTexto(const string &texto, T *destino, size_t &cantidad);

    T1 Ataque2x2Mod26(const string &textocifrado, const string &fragmento, ostream &salida, T **K, T **Pinversa);

    T1 OrdendeAtaque(size_t n);
};
void DemoBFA();


template <typename T>
BFA<T>::BFA() : Cnum(nullptr), K(nullptr), Pinversa(nullptr), n(0)
{
}

template <typename T>
void BFA<T>::NewMemoriaBFA(size_t longText)
{
    // IMPORTANTE: 'n' debe estar asignado (this->n) ANTES de llamar a esta
    // funcion; OrdendeAtaque se encarga de eso.
    Cnum = new T[longText];
    Pinversa = new T *[n];
    for (size_t i = 0; i < n; i++)
        Pinversa[i] = new T[n];
}

template <typename T>
void BFA<T>::DeleteMemoriaBFA()
{
    if (Cnum != nullptr)
    {
        delete[] Cnum;
        Cnum = nullptr;
    }
    if (Pinversa != nullptr)
    {
        for (size_t i = 0; i < n; i++)
            delete[] Pinversa[i];
        delete[] Pinversa;
        Pinversa = nullptr;
    }
    if (K != nullptr)
    {
        for (size_t i = 0; i < n; i++)
            delete[] K[i];
        delete[] K;
        K = nullptr;
    }
}

template <typename T>
void BFA<T>::ConvertirTexto(const string &texto, T *destino, size_t &cantidad)
{
    cantidad = 0;
    for (size_t i = 0; i < texto.size(); i++)
    {
        char c = texto[i];
        if (c >= 'A' && c <= 'Z')
            destino[cantidad++] = static_cast<T>(c - 'A');
        else if (c >= 'a' && c <= 'z')
            destino[cantidad++] = static_cast<T>(c - 'a');
       
    }
}
template <typename T>
T1 BFA<T>::Ataque2x2Mod26(const string &textocifrado, const string &fragmento, ostream &salida, T **K, T **Pinversa)
{
    this->n = 2;

    size_t cantCifrado;
    ConvertirTexto(textocifrado, Cnum, cantCifrado);

    T *fragNum = new T[fragmento.size()];
    size_t cantFrag;
    ConvertirTexto(fragmento, fragNum, cantFrag);
    salida<<endl;
    if (cantFrag < 2)
    {
        salida << "ERROR: el fragmento conocido debe tener al menos 2 letras." << endl;
        delete[] fragNum;
        return T1(false);
    }

    size_t bloques = cantCifrado / 2; 
    T *Pnum = new T[bloques * 2];

    VInvertiblidad<T> V;
    Inversa<T> I;
    I.NewMemoriaI(2);

    bool encontrado = false;

    for (T a = 0; a < 26 && !encontrado; a++)
    for (T b = 0; b < 26 && !encontrado; b++)
    for (T c = 0; c < 26 && !encontrado; c++)
    for (T d = 0; d < 26 && !encontrado; d++)
    {
        K[0][0] = a; K[0][1] = b;
        K[1][0] = c; K[1][1] = d;

       
        if (!V.esInvertibleMod26(V.Determinante(2, K)))
            continue;

        if (!I.InversaMatrix(2, K, Pinversa))
            continue;

        for (size_t bloque = 0; bloque < bloques; bloque++)
        {
            for (size_t fila = 0; fila < 2; fila++)
            {
                T suma = 0;
                for (size_t col = 0; col < 2; col++)
                    suma += Pinversa[fila][col] * Cnum[bloque * 2 + col];
                Pnum[bloque * 2 + fila] = ((suma % 26) + 26) % 26;
            }
        }

        bool coincide = true;
        for (size_t i = 0; i < cantFrag && i < bloques * 2; i++)
        {
            if (Pnum[i] != fragNum[i]) { coincide = false; break; }
        }

        if (coincide)
        {
            salida << "Llave encontrada (2x2 mod 26):" << endl;
            salida << K[0][0] << " " << K[0][1] << endl;
            salida << K[1][0] << " " << K[1][1] << endl;
            salida << "Texto descifrado: ";
            for (size_t i = 0; i < bloques * 2; i++)
                salida << T3(Pnum[i] + 'A');
            salida << endl;
            encontrado = true;
        }
    }

    if (!encontrado)
        salida << "No se encontro ninguna llave 2x2 compatible con el fragmento dado." << endl;

    delete[] fragNum;
    delete[] Pnum;

    return T1(encontrado);
}

template <typename T>
T1 BFA<T>::OrdendeAtaque(size_t n)
{
    if (n != 2)
    {
        cout << "ADVERTENCIA: la fuerza bruta (BFA) solo esta implementada para n = 2. "
             << "No se puede aplicar para n = " << n << "." << endl;
        return T1(false);
    }

    this->n = n;

    string textocifrado, fragmento;
    cout << "Ingrese el texto cifrado: ";
    cin >> textocifrado;
    cout << "Ingrese el fragmento de texto plano conocido: ";
    cin >> fragmento;

    NewMemoriaBFA(textocifrado.size());

    K = new T *[n];
    for (size_t i = 0; i < n; i++)
        K[i] = new T[n];

    return Ataque2x2Mod26(textocifrado, fragmento, cout, K, Pinversa);
}

#endif // __BFA_H__