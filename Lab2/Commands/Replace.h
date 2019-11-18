//
// Created by Daniel on 06/11/2019.
//

#ifndef LAB2_REPLACE_H
#define LAB2_REPLACE_H

#include "Worker.h"
class Replace : public Worker {
 private:
  std::string word1;
  std::string word2;
 public:
  Replace(const std::vector<std::string> &params);
  WorkerType getType() override;
  std::string execute(std::string &text) override;
};

#endif //LAB2_REPLACE_H
