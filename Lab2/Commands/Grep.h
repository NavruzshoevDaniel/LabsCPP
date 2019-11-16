//
// Created by Daniel on 06/11/2019.
//

#ifndef LAB2_GREP_H
#define LAB2_GREP_H

#include "Worker.h"
class Grep : public Worker {
 private:
  std::string word;
 public:
  Grep(const std::vector<std::string> &params);
  std::string execute(std::string &text) override;

};

#endif //LAB2_GREP_H
