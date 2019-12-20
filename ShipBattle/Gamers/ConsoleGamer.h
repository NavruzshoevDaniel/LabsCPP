//
// Created by Daniel on 21/12/2019.
//

#ifndef SHIPBATTLE_CONSOLEGAMER_H
#define SHIPBATTLE_CONSOLEGAMER_H

#include "IGamer.h"
#include "../Factory/GamerMaker.h"

class ConsoleGamer : public IGamer {
 public:
  ~ConsoleGamer() override = default;
  std::vector<Ship> putShips(Map &playerMap, OutType outType) override;
  std::pair<int, int> getCoordToAttack(Map &enemyMap) override;
  bool isCommunicate() override;
};

#endif //SHIPBATTLE_CONSOLEGAMER_H
