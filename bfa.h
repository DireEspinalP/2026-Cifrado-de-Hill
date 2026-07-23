#ifndef __BFA_H__
#define __BFA_H__
#include <string>
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

    T1 Ataque2x2Mod26(const string &textocifrado,const string &fragmento, ostream &salida, T **K, T **Pinversa);
    T1 Ataque3x3Mod26(const string &textocifrado, const string &fragmento, ostream &salida, T **K, T **Pinversa);
    T1 AtaquenxnMod26(const string &textocifrado, const string &fragmento, size_t n, ostream &salida);
    
    T1 OrdendeAtaque(size_t n);
    
};
void DemoBFA();



template <typename T>
void BFA<T>::NewMemoriaBFA(size_t longText)
{
      this->n = n;
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
}

template <typename T>
T1 BFA<T>::Ataque2x2Mod26(const string &textocifrado, const string &fragmento, ostream &salida, T **K, T **Pinversa)
{
    //aplica la fba en 2x2
    
    
}

template <typename T>
T1 BFA<T>::Ataque3x3Mod26(const string &textocifrado, const string &fragmento, ostream &salida, T **K, T **Pinversa)
{
    
}

template <typename T>
T1 BFA<T>::AtaquenxnMod26(const string &textocifrado, const string &fragmento, size_t n, ostream &salida)
{
    salida << "ADVERTENCIA: Fuerza bruta solo esta implementada para n=2 o n=3." << endl;
}

template<typename T>
T1 BFA<T>::OrdendeAtaque(size_t n){
      void (BFA<T>::*n[3])() ={&BFA<T>::Ataque2x2Mod26, &BFA<T>::Ataque3x3Mod26, &BFA<T>::AtaquenxnMod26};
    {
     (this->*n[n-2])();
    }
}

#endif // __BFA_H__