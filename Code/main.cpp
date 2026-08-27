#include <iostream>
#include "cifrado.h"
#include "descifrado.h"
#include "tipos.h"
#include "kpa.h"
#include "bfa.h"
using namespace std;

int main()
{

  cout <<  "---------CIFRADO DE HILL---------"  << endl;
  cout << endl;
  DemoCifradoHill();
  cout<<endl;
  
  cout<<endl;
  cout <<"---------KNOW PLAINTEXT ATTACK---------" << endl;
  DemoKPA();

  cout<<endl;
  cout <<"---------BRUTE FORCE ATTACK---------" << endl;
  DemoBFA();
}