//
// Created by Daniel on 06/11/2019.
//

#include <sstream>
#include <vector>
#include "Sort.h"
std::string Sort::execute(std::string &text) {
  std::string res = "";
  std::istringstream strStream(text);
  std::istream_iterator<std::string> begin(strStream);
  std::istream_iterator<std::string> end;

  std::vector<std::string> words(begin, end);
  std::sort(words.begin(), words.end());
  for (const auto &piece : words) res += piece + " ";

  return res;
}

Sort::Sort(const std::vector<std::string> &params) {
  if(params.size()!=0) throw std::string("Wrong Input params");
}

WorkerType Sort::getType() {
  return WorkerType::INOUT;
}
