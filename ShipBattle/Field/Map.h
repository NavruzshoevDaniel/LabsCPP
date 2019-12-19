//
// Created by Daniel on 04/12/2019.
//

#ifndef SHIPBATTLE_MAP_H
#define SHIPBATTLE_MAP_H

#include <array>

#include "Cell.h"
#include "Ship.h"
#include <cmath>

const int SIZE_MAP = 10;

class Map {
 private:
  typedef std::array<std::array<Cell, SIZE_MAP>, SIZE_MAP> ShipsMap;
  ShipsMap map;
  void fillAroundArea(Ship &ship,std::pair<int,int> coord);

 public:
  ShipsMap &getMap();
  bool isFree(std::pair<int,int> coord);
  bool isInMap(std::pair<int,int> coord);
  bool isPossible(Ship &ship);
  bool isKilledShip(std::pair<int, int> coord);

  void clearMap();
  void changeAroundArea(Ship &ship);
  bool putShip(Ship &ship);

};

#endif //SHIPBATTLE_MAP_H
