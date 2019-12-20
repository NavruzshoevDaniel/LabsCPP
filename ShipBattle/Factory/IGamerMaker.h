//
// Created by Daniel on 20/12/2019.
//

#ifndef SHIPBATTLE_IGAMERMAKER_H
#define SHIPBATTLE_IGAMERMAKER_H

#include <memory>
#include "../Gamers/IGamer.h"

class IGamerMaker {
 public:
  virtual IGamer *create() const = 0;
};

#endif //SHIPBATTLE_IGAMERMAKER_H
