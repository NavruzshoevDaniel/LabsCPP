//
// Created by Daniel on 11/11/2019.
//

#ifndef LAB2_WORKERCREATOR_H
#define LAB2_WORKERCREATOR_H

#include "ICreator.h"
#include "BlockFactory.h"

template<class C>
class Creator : public ICreator {
 public:

  Creator(const std::string &id) {
    BlockFactory::Instance().add(id, this);
  }

  Worker *create(const std::vector<std::string> &params) const {
    return new C(params);
  }

};

#endif //LAB2_WORKERCREATOR_H
