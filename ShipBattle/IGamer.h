//
// Created by Daniel on 05/12/2019.
//

#ifndef SHIPBATTLE_GAMER_H
#define SHIPBATTLE_GAMER_H

#include <string>
#include "Console/ConsoleOperations.h"
#include <random>
#include <list>

class IGamer {

 public:
  virtual std::vector<Ship> putShips(Map &playerMap, OutType outType) = 0;
  virtual std::pair<int, int> getCoordToAttack(Map &enemyMap) = 0;
  virtual bool isCommunicate() = 0;

  virtual ~IGamer() = default;
};

class ConsoleGamer : public IGamer {
 public:
  std::vector<Ship> putShips(Map &playerMap, OutType outType) override;
  std::pair<int, int> getCoordToAttack(Map &enemyMap) override;
  bool isCommunicate() override;
};

class RandomGamer : public IGamer {
 private:
  orientation randomOrientation();
  std::pair<int, int> randomCoord();
  bool isCommunicate() override;

 public:
  std::vector<Ship> putShips(Map &playerMap, OutType outType) override;
  std::pair<int, int> getCoordToAttack(Map &enemyMap) override;
};

class OptimalGamer : public IGamer {
 private:
  typedef std::vector<std::pair<int, int> > Coordinates;
  Coordinates activePoints;


  int enemyCountShips[4];
  bool hitToKill=false;
  std::pair<int, int> hit = {0, 0};
  std::pair<int, int> planned = {-1, 0};

  std::vector<std::pair<int, int>> currentShip;
  orientation curOrientation;
  std::list<std::pair<int, int>> allegedPart;
  //std::vector<std::pair<int, int>> allegedPart;


  //functions for putShips
  unsigned long commonCoord(Map &playerMap,Ship &ship);
  bool isFull(int countShips[]);
  void updateActivePoints(Map &playerMap,Ship &tmpShip);
  void addActivePoint(Map &playerMap,std::pair<int,int> coord);
  void addSingleShips(Map &playerMap,std::vector<Ship> &ships);
  //functions for getCoordToAttack
  void shoot(Map &map);
  void finish(Map &map);

  void searchQuadrupleTripleDouble();
  void searchSolo();

  void fillAllegedPart(Map &map);
  void addAllegedCoord(Map &map,int x,int y);

  void whichOrientation();
 public:
  OptimalGamer();
  ~OptimalGamer() override = default;
  std::vector<Ship> putShips(Map &playerMap, OutType outType) override;
  std::pair<int, int> getCoordToAttack(Map &enemyMap) override;
  bool isCommunicate() override;
};

#endif //SHIPBATTLE_GAMER_H
