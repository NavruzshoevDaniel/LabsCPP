//
// Created by Daniel on 18.09.2019.
//

#include <cmath>
#include "BitManipulationForTrit.h"
namespace BitManipulation {
//Get and set
trit getITrit(unsigned *adress, int i) {
  unsigned maskafirst = pow(2, sizeof(unsigned) * 8 - 1 - (i % (sizeof(unsigned) * 4)) * 2);
  unsigned maskasecond = pow(2, sizeof(unsigned) * 8 - 2 - (i % (sizeof(unsigned) * 4)) * 2);

  return ((*adress & maskafirst) == 0) ? Unknown : ((*adress & maskasecond) == 0 ? False : True);
}

void setITrit(unsigned *adress, trit trt, int i) {

  unsigned maskafirst = pow(2, sizeof(unsigned) * 8 - 1 - (i % (sizeof(unsigned) * 4)) * 2);
  unsigned maskasecond = pow(2, sizeof(unsigned) * 8 - 2 - (i % (sizeof(unsigned) * 4)) * 2);

  if (trt == Unknown) {
    *adress &= ~(maskafirst + maskasecond);
  } else if (trt == True) {
    *adress |= maskafirst + maskasecond;
  } else {
    *adress |= maskafirst;
    *adress &= ~maskasecond;
  }
}

//trits Operations
trit orOperation(trit trt1, trit trt2) {
  if ((trt1 == True) || (trt2 == True))
    return True;
  else if ((trt1 == Unknown) || (trt2 == Unknown))
    return Unknown;
  else
    return False;
}

trit notOperation(trit trt) {
  if (trt == True)
    return False;
  else if (trt == False)
    return True;
  else return Unknown;
}

trit andOperation(trit trt1, trit trt2) {

  if ((trt1 == False) || (trt2 == False))
    return False;
  else if ((trt1 == Unknown) || (trt2 == Unknown))
    return Unknown;
  else
    return True;
}

string getStrTrit(trit trt) {
  if (trt == True)
    return "True";
  else if (trt == False)
    return "False";
  else
    return "Unknown";
}

}
