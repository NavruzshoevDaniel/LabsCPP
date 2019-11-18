//
// Created by Daniel on 30/10/2019.
//

#include <fstream>
#include "ReadFile.h"
std::string ReadFile::execute(std::string &text) {
  std::ifstream fin(text);

  if (!fin.is_open()) throw std::string("Can't open file from 'readfile'");
  std::string buf((std::istreambuf_iterator<char>(fin)),
                  std::istreambuf_iterator<char>());
  fin.close();
  return buf;
}

ReadFile::ReadFile(const std::vector<std::string> &params) {
  if(params.size()!=1) throw std::string("Wrong Input params");
  this->nameFile = params[0];
}

WorkerType ReadFile::getType() {
  return WorkerType::IN;
}
