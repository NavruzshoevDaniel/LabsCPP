//
// Created by Daniel on 28/11/2019.
//

#include "Ship.h"
Ship::Ship(std::pair<int, int> xy, std::string orient, int length) {

  if (orient == "v") {
    this->orient = vertical;
    for (int i = 0; i < length; ++i)
      xyCoordinates.push_back(std::make_pair(xy.first + i, xy.second));
  } else if (orient == "h") {
    this->orient = horisantal;
    for (int i = 0; i < length; ++i)
      xyCoordinates.push_back(std::make_pair(xy.first, xy.second + i));
  }

  this->length = length;
}

orientation Ship::getOrientation() {
  return this->orient;
}

Ship::Coordinates &Ship::getCoordinates() {
  return this->xyCoordinates;
}

int Ship::getLength() {
  return this->length;
}

Ship::Coordinates &Ship::getAroundArea() {
  return this->aroundArea;
}

void Ship::setAroundArea(int x, int y) {
  this->aroundArea.push_back(std::make_pair(x, y));
}

Ship::Ship(std::pair<int, int> xy, orientation orient, int length) {

  for (int i = 0; i < length; ++i) {

    switch (orient) {
      case vertical: {
        this->orient = vertical;
        xyCoordinates.push_back(std::make_pair(xy.first + i, xy.second));
        break;
      }
      case horisantal: {
        this->orient = horisantal;

        xyCoordinates.push_back(std::make_pair(xy.first, xy.second + i));
        break;
      }
      case left: {
        this->orient = left;
        xyCoordinates.push_back(std::make_pair(xy.first - i, xy.second));
        break;
      }
      case up: {
        this->orient = up;
        xyCoordinates.push_back(std::make_pair(xy.first, xy.second - i));
        break;
      }
    }
  }

  this->length = length;
}

std::pair<int, int> Ship::getStart() {
  return this->xyCoordinates[0];
}

std::pair<int, int> Ship::getEnd() {
  return this->xyCoordinates[length];
}

