//
// Created by Daniel on 28/11/2019.
//

#ifndef NAVALBATTLE_SHIP_H
#define NAVALBATTLE_SHIP_H
#include <utility>
#include <string>
#include <vector>

enum orientation {
  vertical,
  horisantal,
  left,
  up

};

class Ship {
 private:
  typedef std::vector<std::pair<int, int> > Coordinates;
  Coordinates xyCoordinates;
  Coordinates aroundArea;
  orientation orient;
  int length = 0;

 public:
  Ship(std::pair<int, int> xy, std::string orient, int length);
  Ship(std::pair<int, int> xy, orientation orient, int length);

  ~Ship() = default;
  Ship(const Ship &ship) = default;

  orientation getOrientation();
  Coordinates &getCoordinates();
  Coordinates &getAroundArea();
  std::pair<int,int> getStart();
  std::pair<int,int> getEnd();

  void setAroundArea(int x, int y);
  int getLength();

};

#endif //NAVALBATTLE_SHIP_H
