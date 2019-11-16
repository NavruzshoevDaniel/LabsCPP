//
// Created by Daniel on 11/11/2019.
//

#include "BlockFactory.h"

Worker *BlockFactory::create(const std::string &id, const std::vector<std::string> &params) {
  typename FactoryMap::iterator it = factory.find(id);
  if (it != factory.end())
    return it->second->create(params);
  return nullptr;
}

BlockFactory &BlockFactory::Instance() {
  static BlockFactory instance;
  return instance;
}

void BlockFactory::add(const std::string &id, ICreator *creator) {
  if (factory.find(id) != factory.end())
    throw std::string("fuck you");
  factory[id] = creator;
}


