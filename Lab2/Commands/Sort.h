//
// Created by Daniel on 06/11/2019.
//

#ifndef LAB2_SORT_H
#define LAB2_SORT_H

#include "Worker.h"
class Sort : public Worker {
 public:
  Sort() {}
  Sort(const std::vector<std::string> &params);
  WorkerType getType() override;
  std::string execute(std::string &text) override;
};

#endif //LAB2_SORT_H
