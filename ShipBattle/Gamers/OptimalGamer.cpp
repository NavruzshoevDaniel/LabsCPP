//
// Created by Daniel on 21/12/2019.
//

#include "OptimalGamer.h"

static GamerMaker<OptimalGamer> optimalG("optimal");

std::vector<Ship> OptimalGamer::putShips(Map &playerMap, OutType outType) {

  std::vector<Ship> newPlayerShips;
  int countShips[TOTAL_SHIPS];

  std::random_device rd;
  std::default_random_engine generator(rd());
  std::uniform_int_distribution<int> distribution(2, TOTAL_SHIPS);

  for (int i = 0; i < TOTAL_SHIPS; ++i)
    countShips[i] = TOTAL_SHIPS - i;
  countShips[0] = 0;

  while (!isFull(countShips)) {

    int minArea = INT_MAX;
    int sizeShip = distribution(generator);
    while (countShips[sizeShip - 1] == 0)
      sizeShip = distribution(generator);

    std::vector<Ship> availableShips;

    for (auto &coord:activePoints) {

      for (int i = 0; i < 4; ++i) {

        Ship tmpShip(coord, (orientation) i, sizeShip);

        if (playerMap.isPossible(tmpShip)) {
          unsigned long aroundSize = tmpShip.getAroundArea().size() - commonCoord(playerMap, tmpShip);

          if (minArea > aroundSize) {
            availableShips.clear();
            availableShips.push_back(tmpShip);
            minArea = aroundSize;
          } else if (minArea == aroundSize)
            availableShips.push_back(tmpShip);
        }
      }
    }

    std::uniform_int_distribution<int> distAvailableShips(0, (availableShips.size() - 1));
    int numberShipInVector = distAvailableShips(generator);

    Ship newShip = availableShips.at(numberShipInVector);

    playerMap.putShip(newShip);
    newPlayerShips.push_back(newShip);
    countShips[newShip.getLength() - 1]--;
    updateActivePoints(playerMap, newShip);

  }

  addSingleShips(playerMap, newPlayerShips);

  return newPlayerShips;
}

OptimalGamer::OptimalGamer() {
  for (int &enemyCountShip : enemyCountShips)
    enemyCountShip = 0;

  activePoints.push_back(std::make_pair(0, 0));
  activePoints.push_back(std::make_pair(0, 9));
  activePoints.push_back(std::make_pair(9, 0));
  activePoints.push_back(std::make_pair(9, 9));
}

unsigned long OptimalGamer::commonCoord(Map &playerMap, Ship &ship) {
  unsigned long commonPoints = 0;
  for (auto &areaCoord: ship.getAroundArea())
    if (playerMap.getMap()[areaCoord.first][areaCoord.second].getStatus() == notToAdd)
      commonPoints++;

  return commonPoints;
}

bool OptimalGamer::isFull(int *countShips) {

  for (int i = 0; i < TOTAL_SHIPS; ++i)
    if (countShips[i] != 0)
      return false;

  return true;
}

void OptimalGamer::updateActivePoints(Map &map, Ship &tmpShip) {
  auto start = std::find(activePoints.begin(), activePoints.end(), tmpShip.getCoordinates()[0]);
  activePoints.erase(start);
  int x=0;
  int y=0;

    for (float i = 0; i <= M_PI * 2; i += 1.57) {
      x = static_cast<int>(round(cos(i)*2) + tmpShip.getStart().first);
      y = static_cast<int>(round(sin(i)*2) + tmpShip.getStart().second);

      addActivePoint(map, std::make_pair(x, y));
    }

}

void OptimalGamer::addActivePoint(Map &playerMap, std::pair<int, int> coord) {
  if (playerMap.isInMap(coord)&&playerMap.isFree(coord))
    activePoints.push_back(coord);
}

void OptimalGamer::addSingleShips(Map &playerMap, std::vector<Ship> &ships) {
  std::random_device rd;
  std::default_random_engine generator(rd());
  std::uniform_int_distribution<int> dist(0, 9);

  for (int i = 0; i < 4; i++) {
    int x = dist(generator);
    int y = dist(generator);

    while (!playerMap.isFree(std::make_pair(x, y))) {
      x = dist(generator);
      y = dist(generator);
    }

    Ship ship(std::make_pair(x, y), orientation::up, 1);
    playerMap.putShip(ship);
    ships.push_back(ship);
  }
}

std::pair<int, int> OptimalGamer::getCoordToAttack(Map &enemyMap) {

  if (!hitToKill) {
    shoot(enemyMap);
    return planned;
  } else {
    finish(enemyMap);
    return hit;
  }

}

bool OptimalGamer::isCommunicate() {
  return false;
}

void OptimalGamer::searchQuadrupleTripleDouble() {

  if (((planned.second + 1) >= 10) && ((planned.first + 4) > 9)) {
    planned.first = -3;
    planned.second = 0;
    //for searching Triple and Double ships
  }

  if (planned.first == 9) {
    planned.first = 0;
    planned.second++;
  } else {
    if ((planned.first + 4) > 9) {
      planned.second += 1;
      planned.first = (planned.first + 4) % 9;
    } else {
      planned.first = planned.first + 4;
    }
  }
}

void OptimalGamer::searchSolo() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  std::uniform_int_distribution<int> distribution(0, 9);

  planned.first = distribution(generator);
  planned.second = distribution(generator);
}

void OptimalGamer::shoot(Map &map) {
  if (enemyCountShips[3] != 1 || enemyCountShips[2] != 2 || enemyCountShips[1] != 3)
    searchQuadrupleTripleDouble();
  else {
    searchSolo();
  }
  statusCell status = map.getMap()[planned.first][planned.second].getStatus();

  if ((soloShip <= status) && (status <= quadrupleShip)) {
    hitToKill = true;
    currentShip.
        emplace_back(planned);
    fillAllegedPart(map);

  }

}

void OptimalGamer::finish(Map &map) {
  if (allegedPart.empty()) {
    hitToKill = false;
    enemyCountShips[currentShip.size() - 1]++;
    currentShip.clear();
  } else {

    hit = allegedPart.back();
    allegedPart.pop_back();

    statusCell status = map.getMap()[hit.first][hit.second].getStatus();

    if ((soloShip <= status) && (status <= quadrupleShip)) {
      currentShip.emplace_back(hit);
      fillAllegedPart(map);
    }

  }
}

void OptimalGamer::fillAllegedPart(Map &map) {

  int x = 0;
  int y = 0;
  if (currentShip.size() < 2) {

    for (float i = 0; i <= M_PI * 2; i += 1.58) {
      x = static_cast<int>(round(cos(i)) + planned.first);
      y = static_cast<int>(round(sin(i)) + planned.second);

      addAllegedCoord(map, x, y);
    }
  } else {

    whichOrientation();
    x = currentShip.back().first;
    y = currentShip.back().second;

    if (curOrientation == right) {
      for (auto iter = allegedPart.begin(); iter != allegedPart.end();)
        if (iter->first != currentShip[0].first)
          iter = allegedPart.erase(iter);
        else iter++;

      addAllegedCoord(map, x, y + 1);
      addAllegedCoord(map, x, y - 1);

    } else {

      for (auto iter = allegedPart.begin(); iter != allegedPart.end();)
        if (iter->second != currentShip[0].second)
          iter = allegedPart.erase(iter);
        else iter++;

      addAllegedCoord(map, x + 1, y);
      addAllegedCoord(map, x - 1, y);
    }
  }
}

void OptimalGamer::whichOrientation() {
  curOrientation = currentShip[0].first == currentShip[1].first ? right : down;
}

void OptimalGamer::addAllegedCoord(Map &map, int x, int y) {
  std::pair<int, int> coord = std::make_pair(x, y);

  if (map.isInMap(coord) && !map.isKilledShip(coord))
    allegedPart.emplace_back(coord);
}