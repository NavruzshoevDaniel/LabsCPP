//
// Created by Daniel on 20/12/2019.
//

#ifndef SHIPBATTLE_GAMERFACTORY_H
#define SHIPBATTLE_GAMERFACTORY_H

#include <map>
#include "IGamerMaker.h"

class GamerFactory {
 private:
  std::map<std::string, IGamerMaker *> makers;
 public:

  static GamerFactory &Instance();
  IGamer *createGamer(std::string &typeGamer) const;
  void registerMaker(const std::string &key, IGamerMaker *maker);
};

#endif //SHIPBATTLE_GAMERFACTORY_H
