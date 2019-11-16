//
// Created by Daniel on 11/11/2019.
//

#ifndef LAB2_ABSTRACTWORKERCREATOR_H
#define LAB2_ABSTRACTWORKERCREATOR_H

#include "../Commands/Worker.h"

class ICreator {
 public:
  virtual Worker *create(const std::vector<std::string> &params) const = 0;
};
#endif //LAB2_ABSTRACTWORKERCREATOR_H
