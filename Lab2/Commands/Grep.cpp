//
// Created by Daniel on 06/11/2019.
//

#include <sstream>
#include "Grep.h"

std::string Grep::execute(std::string &text) {

  std::string res = "";
  std::string line;
  std::istringstream tmpStream(text);
  while (std::getline(tmpStream, line))
    if (line.find(word) != std::string::npos) res += line+"\n";

  return res;
}

Grep::Grep(const std::vector<std::string> &params) {
  if(params.size()!=1) throw std::string("Wrong Input params");
  this->word = params[0];
}

WorkerType Grep::getType() {
  return WorkerType::INOUT;
}
