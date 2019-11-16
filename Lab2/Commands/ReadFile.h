//
// Created by Daniel on 30/10/2019.
//

#ifndef LAB2_READFILE_H
#define LAB2_READFILE_H

#include <cstdio>
#include "Worker.h"
class ReadFile : public Worker {
 private:
  std::string nameFile;
 public:
  ReadFile(const std::vector<std::string> &params);
  std::string execute(std::string &text) override;
};

#endif //LAB2_READFILE_H
