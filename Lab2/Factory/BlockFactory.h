//
// Created by Daniel on 11/11/2019.
//

#ifndef LAB2_BLOCKFACTORY_H
#define LAB2_BLOCKFACTORY_H

#include <string>
#include <map>
#include "ICreator.h"

typedef std::map<std::string, ICreator *> FactoryMap;

class BlockFactory {
 protected:
  FactoryMap factory;
 public:

  void add(const std::string &id, ICreator *creator);

  std::shared_ptr<Worker> create(const std::string &id, const std::vector<std::string> &params);

  static BlockFactory &Instance();// - SINGLETON
};

#endif //LAB2_BLOCKFACTORY_H
