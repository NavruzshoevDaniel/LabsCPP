//
// Created by Daniel on 06/11/2019.
//

#include <fstream>
#include "Dump.h"

Dump::Dump(const std::vector<std::string> &params) {
  this->outputFile = params[0];
}

std::string Dump::execute(std::string &text) {
  std::ofstream fout(outputFile);
  fout<<text;
  fout.close();
  return text;
}
