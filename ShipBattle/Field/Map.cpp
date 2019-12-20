//
// Created by Daniel on 04/12/2019.
//


#include "Map.h"
Map::ShipsMap &Map::getMap() {
  return this->map;
}

void Map::changeAroundArea(Ship &ship) {
  for (auto &cell: ship.getAroundArea())
    map[cell.first][cell.second].setStatus(missOrArea);

}

bool Map::isFree(std::pair<int, int> coord) {
  return (map[coord.first][coord.second].getStatus() == notShip);

}

bool Map::isInMap(std::pair<int, int> coord) {
  return ((coord.first >= 0) && (coord.first < SIZE_MAP)
      && (coord.second >= 0) && (coord.second < SIZE_MAP));
}

bool Map::putShip(Ship &ship) {

  for (auto &coord: ship.getCoordinates())
    if (!isInMap(coord) || !isFree(coord))
      return false;

  for (auto &coord: ship.getCoordinates())
    map[coord.first][coord.second].setStatus((statusCell) ship.getLength());

  for (auto &coord: ship.getCoordinates())
    fillAroundArea(ship, coord);

  return true;
}

void Map::fillAroundArea(Ship &ship, std::pair<int, int> coord) {
  int x = 0;
  int y = 0;

  for (float i = 0; i <= M_PI * 2; i += 0.786) {
    x = static_cast<int>(round(cos(i)) + coord.first);
    y = static_cast<int>(round(sin(i)) + coord.second);

    if (isInMap(std::make_pair(x, y)) && (isFree(std::make_pair(x, y)) || (map[x][y].getStatus() == notToAdd))) {
      map[x][y].setStatus(notToAdd);
      ship.setAroundArea(x,y);
    }

  }
}

bool Map::isPossible(Ship &ship) {
  for (auto &coord: ship.getCoordinates())
    if (!isFree(coord) || !isInMap(coord))
      return false;

  return true;
}

bool Map::isKilledShip(std::pair<int, int> coord) {
  return map[coord.first][coord.second].getStatus()==killedShip;
}

void Map::clearMap() {
  for (int i = 0; i < SIZE_MAP; ++i)
    for (int j = 0; j < SIZE_MAP; ++j)
      map[i][j].setStatus(notShip);


}
