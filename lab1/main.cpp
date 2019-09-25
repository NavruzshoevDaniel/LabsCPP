#include <iostream>
#include <unordered_map>
#include "Tritset.h"
#include "BitManipulationForTrit.h"

using namespace Trits;
using namespace BitManipulation;
int main() {
  Tritset a(5);

  int co=a.length();
  a[4] = True;
  cout <<a[4]<<endl;
  a[2] = False;
  a[1] = True;
  a[15]=True;
  a[13]=False;
  a[14]=True;
  a[17]=False;
  a.cardinality();

  Tritset b(7);
  b[1] = False;
  b[2] = True;
  a[1]=b[1];
  Tritset c=a|b;
  int s=a.cardinality(Unknown);



  /*unsigned mas[10];
  if (a[2] == Unknown) {
    int k = 0;
  }
  a[17] = True;


  a[2] = False;
  a[3] = True;
  a[4] = True;
  a[33] = True;
  a[33]=Unknown;
  if (a[2] == a[200]) {
    int g = 0;
  }*/
  return 0;
}