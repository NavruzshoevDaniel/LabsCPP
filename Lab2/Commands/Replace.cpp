//
// Created by Daniel on 06/11/2019.
//

#include "Replace.h"
std::string Replace::execute(std::string &text) {
  size_t pos = text.find(word1);

  while (pos != std::string::npos) {
    text.replace(pos, word1.length(), word2);
    pos = text.find(word1);
  }
  return text;
}
Replace::Replace(const std::vector<std::string> &params) {
  this->word1=params[0];
  this->word2=params[1];
}
