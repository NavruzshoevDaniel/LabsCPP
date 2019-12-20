//
// Created by Daniel on 21/12/2019.
//

#ifndef SHIPBATTLE_RANDOMGAMER_H
#define SHIPBATTLE_RANDOMGAMER_H

#include "IGamer.h"
#include "../Factory/GamerMaker.h"

class RandomGamer : public IGamer {
 private:
  orientation randomOrientation();
  std::pair<int, int> randomCoord();
  bool isCommunicate() override;

 public:
  ~RandomGamer() override = default;
  std::vector<Ship> putShips(Map &playerMap, OutType outType) override;
  std::pair<int, int> getCoordToAttack(Map &enemyMap) override;
};

#endif //SHIPBATTLE_RANDOMGAMER_H
