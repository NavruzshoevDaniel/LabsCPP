//
// Created by Daniel on 18.09.2019.
//

#ifndef LAB1_BITMANIPULATIONFORTRIT_H
#define LAB1_BITMANIPULATIONFORTRIT_H
#include <string>
#include "Tritset.h"
namespace BitManipulation {
using namespace Trits;

trit getITrit(unsigned *arr, int i);
void setITrit(unsigned *arr, trit trt, int i);

string getStrTrit(trit trt);

trit notOperation(trit trt1);
trit orOperation(trit trt1, trit trt2);
trit andOperation(trit trt1, trit trt2);
}

#endif //LAB1_BITMANIPULATIONFORTRIT_H
