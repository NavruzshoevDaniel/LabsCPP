//
// Created by Daniel on 06/11/2019.
//

#include <fstream>
#include "WriteFile.h"

WriteFile::WriteFile(const std::vector<std::string> &params) {
  if(params.size()!=1) throw std::string("Wrong Input params");
  this->outputFile = params[0];
}

std::string WriteFile::execute(std::string &text) {
  std::ofstream fout(outputFile);
  fout << text;
  return std::string();
}

WorkerType WriteFile::getType() {
  return WorkerType::OUT;
}
