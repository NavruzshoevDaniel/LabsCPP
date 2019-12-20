//
// Created by Daniel on 20/12/2019.
//

#include "GamerFactory.h"

GamerFactory &GamerFactory::Instance() {
  static GamerFactory factory;
  return factory;
}

void GamerFactory::registerMaker(const std::string &key, IGamerMaker *maker) {

  if (makers.find(key) != makers.end()) {
    throw std::string("Multiple makers for given key!");
  }

  makers[key] = maker;
}

IGamer *GamerFactory::createGamer(std::string &typeGamer) const {

  auto i = makers.find(typeGamer);

  if (i == makers.end())
    throw std::string("Такого типа игрока не существует");

  IGamerMaker *maker = i->second;

  return maker->create();
}
