//
// Created by Daniel on 20/12/2019.
//

#ifndef SHIPBATTLE_GAMERMAKER_H
#define SHIPBATTLE_GAMERMAKER_H

#include "GamerFactory.h"

template<typename T>
class GamerMaker : IGamerMaker {
 public:

  GamerMaker(const std::string &key) {
    GamerFactory::Instance().registerMaker(key, this);
  }

  IGamer *create() const override {
    return new T();
  }

};

#endif //SHIPBATTLE_GAMERMAKER_H
