//
// Created by Daniel on 06/11/2019.
//

#ifndef LAB2_WRITEFILE_H
#define LAB2_WRITEFILE_H

#include "Worker.h"
class WriteFile : public Worker {
 private:
  std::string outputFile;
 public:
  WriteFile(const std::vector<std::string> &params);
  std::string execute(std::string &text) override;
};

#endif //LAB2_WRITEFILE_H
