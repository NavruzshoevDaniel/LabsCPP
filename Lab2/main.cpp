#include <iostream>

#include "WorkFlow.h"

int main(int arg,char **argv) {
  WorkFlow workFlow;
  ifstream file;
  try {
    workFlow.launch("in.txt");
  }
  catch (std::string &ex) {
    std::cout << ex << endl;
  }

  return 0;
}