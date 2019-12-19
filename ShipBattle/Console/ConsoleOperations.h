//
// Created by Daniel on 02/12/2019.
//

#ifndef NAVALBATTLE_CONSOLEOPERATIONS_H
#define NAVALBATTLE_CONSOLEOPERATIONS_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "../Field/Map.h"
#include "../StringResources.h"

enum class OutType {
  showFirstMap,
  showSecondMap,
};

OutType operator!(OutType &type);


class ConsoleOperations {
 private:

  std::string whtShow(Cell &cell, OutType outMap);
  bool checkCoordinates(std::string &strX, std::string &strY);
  bool checkOrientation(std::string &strOrientir);
  void viewWelcomeAndNames();

  int convertSecondCoordinate(std::string &secondCoord);

 public:

  std::pair<int, int> readingCoordinates(int lengthShip);
  std::string readingOrientation(int lengthShip);
  std::pair<int, int> readingCoordinatesToAttack();
  void viewBoard(Map &firstMap, Map &secondMap, OutType outType);
};

#endif //NAVALBATTLE_CONSOLEOPERATIONS_H
