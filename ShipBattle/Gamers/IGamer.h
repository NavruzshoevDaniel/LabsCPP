//
// Created by Daniel on 05/12/2019.
//

#ifndef SHIPBATTLE_GAMER_H
#define SHIPBATTLE_GAMER_H

#include <string>
#include <random>
#include <list>
#include "../Console/ConsoleOperations.h"

const int TOTAL_SHIPS=4;

class IGamer {

 public:
  virtual std::vector<Ship> putShips(Map &playerMap, OutType outType) = 0;
  virtual std::pair<int, int> getCoordToAttack(Map &enemyMap) = 0;
  virtual bool isCommunicate() = 0;

  virtual ~IGamer() = default;
};

#endif //SHIPBATTLE_GAMER_H
