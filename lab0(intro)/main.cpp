#include <iostream>
#include "Counter.h"
using namespace Counter;

int main(int argc, char **argv) {
  Freq f(argv[1], argv[2]);
  f.outFreq();
  return 0;
}