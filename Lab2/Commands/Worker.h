//
// Created by Daniel on 10/11/2019.
//

#ifndef LAB2_WORKER_H
#define LAB2_WORKER_H
#include <string>
#include <vector>

enum class WorkerType {
    IN,
    OUT,
    INOUT
};

class Worker {
 public:
  virtual ~Worker() = default;
  virtual WorkerType getType() = 0;
  virtual std::string execute(std::string &text) = 0;
};

#endif //LAB2_WORKER_H
