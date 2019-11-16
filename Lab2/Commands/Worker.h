//
// Created by Daniel on 10/11/2019.
//

#ifndef LAB2_WORKER_H
#define LAB2_WORKER_H
#include <string>
#include <vector>

class Worker {
 public:
  virtual std::string execute(std::string &text) = 0;
};

#endif //LAB2_WORKER_H
