//
// Created by Daniel on 21/12/2019.
//

#include "RandomGamer.h"

static GamerMaker<RandomGamer> randomG("random");

std::vector<Ship> RandomGamer::putShips(Map &playerMap, OutType outType) {
  std::pair<int, int> xyCoord;
  std::vector<Ship> newPlayerShips;
  orientation orient = down;
  bool checkInMap = false;

  for (int i = TOTAL_SHIPS; i > 0; --i) {
    for (int j = 0; j <= TOTAL_SHIPS - i; ++j) {
      while (!checkInMap) {

        xyCoord = randomCoord();
        if (i != 1)
          orient = randomOrientation();

        Ship ship(xyCoord, orient, i);

        checkInMap = playerMap.putShip(ship);

        if (checkInMap)
          newPlayerShips.push_back(ship);
      }
      checkInMap = false;
    }
  }
  return newPlayerShips;
}

orientation RandomGamer::randomOrientation() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  std::uniform_int_distribution<int> distribution(0, 1);

  int orientation = distribution(generator);

  return orientation ? down : right;
}

std::pair<int, int> RandomGamer::randomCoord() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  std::uniform_int_distribution<int> distribution(0, 9);
  int x = distribution(generator);
  int y = distribution(generator);

  return std::make_pair(x, y);
}

std::pair<int, int> RandomGamer::getCoordToAttack(Map &enemyMap) {
  return randomCoord();
}

bool RandomGamer::isCommunicate() {
  return false;
}
