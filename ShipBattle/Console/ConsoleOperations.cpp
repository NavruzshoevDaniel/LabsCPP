//
// Created by Daniel on 02/12/2019.
//


#include "ConsoleOperations.h"

bool ConsoleOperations::checkCoordinates(std::string &strX, std::string &strY) {
  return (strX.size() == 1) && (strY.size() == 1) && (strX[0] >= '0') && (strX[0] <= '9') && (((strY[0] >= 'A')
      && (strY[0] <= 'J')) || ((strY[0] >= 'a') && (strY[0] <= 'j')));
}

bool ConsoleOperations::checkOrientation(std::string &strOrientir) {
  return strOrientir.size() == 1 && ((strOrientir[0] == 'v') || (strOrientir[0] == 'h'));
}

std::pair<int, int> ConsoleOperations::readingCoordinates(int lengthShip) {
  std::string coordinateX;
  std::string coordinateY;

  std::cout << WRITECOORDINATES << lengthShip << std::endl;
  std::cin >> coordinateX >> coordinateY;

  while (!checkCoordinates(coordinateX, coordinateY)) {
    std::cout << ERRORWRITECOORDINATES << std::endl;
    std::cin.clear();
    std::cout << WRITECOORDINATES << lengthShip << std::endl;
    std::cin >> coordinateX >> coordinateY;
  }

  return std::make_pair(std::stoi(coordinateX), convertSecondCoordinate(coordinateY));
}

std::string ConsoleOperations::readingOrientation(int lengtShip) {
  std::string orientation;
  std::cout << WRITEORIENTATION << lengtShip << std::endl;
  std::cin >> orientation;

  while (!checkOrientation(orientation)) {
    std::cout << ERRORWRITEORIENTATION << std::endl;
    std::cin.clear();
    std::cout << WRITEORIENTATION << lengtShip << std::endl;
    std::cin >> orientation;
  }
  return orientation;
}

int ConsoleOperations::convertSecondCoordinate(std::string &secondCoord) {

  if (secondCoord == "A" || secondCoord == "a")
    return 0;
  else if (secondCoord == "B" || secondCoord == "b")
    return 1;
  else if (secondCoord == "C" || secondCoord == "c")
    return 2;
  else if (secondCoord == "D" || secondCoord == "d")
    return 3;
  else if (secondCoord == "E" || secondCoord == "e")
    return 4;
  else if (secondCoord == "F" || secondCoord == "f")
    return 5;
  else if (secondCoord == "G" || secondCoord == "g")
    return 6;
  else if (secondCoord == "H" || secondCoord == "h")
    return 7;
  else if (secondCoord == "I" || secondCoord == "i")
    return 8;
  else if (secondCoord == "J" || secondCoord == "j")
    return 9;
  else return 0;

}


void ConsoleOperations::viewBoard(Map &firstMap, Map &secondMap, OutType outType) {

  viewWelcomeAndNames();

  std::cout << "|     A  B  C  D  E  F  G  H  I  J |       A  B  C  D  E  F  G  H  I  J  |" << std::endl;

  for (int i = 0; i < SIZE_MAP; ++i) {

    std::cout << "|" << std::setw(3) << i;
    for (int j = 0; j < SIZE_MAP; ++j) {
      std::cout << std::setw(3) << whtShow(firstMap.getMap()[i][j], outType);
    }
    std::cout << " |";
    std::cout << std::setw(5) << i;
    for (int j = 0; j < SIZE_MAP; ++j) {
      std::cout << std::setw(3) << whtShow(secondMap.getMap()[i][j], !outType);
    }
    std::cout << "  |" << std::endl;
  }

  std::cout << "--------------------------------------------------------------------------" << std::endl;
}


std::string ConsoleOperations::whtShow(Cell &cell, OutType outMap) {

  if (outMap == OutType::showFirstMap)
    switch (cell.getStatus()) {
      case killedShip:return "@";
      case notShip:return "*";
      case notToAdd:return " ";
      case soloShip:return "1";
      case doubleShip:return "2";
      case tripleShip:return "3";
      case quadrupleShip:return "4";
      case missOrArea:return "X";

      default:return "*";
    }
  else
    switch (cell.getStatus()) {
      case killedShip:return "@";
      case missOrArea:return "X";

      default:return "*";
    }

}

void ConsoleOperations::viewWelcomeAndNames() {

  std::string line;
  std::ifstream welcomeFile("welcomeToBattleShip.txt");

  if (welcomeFile.is_open()) {
    while (!welcomeFile.eof()) {
      getline(welcomeFile, line);
      std::cout << line << std::endl;
    }
    welcomeFile.close();
  }
}

std::pair<int, int> ConsoleOperations::readingCoordinatesToAttack() {
  std::string coordinateX;
  std::string coordinateY;

  std::cout << WRITECOORDTOATTACK << std::endl;
  std::cin >> coordinateX >> coordinateY;

  while (!checkCoordinates(coordinateX, coordinateY)) {
    std::cout << ERRORWRITECOORDINATES << std::endl;
    std::cin.clear();
    std::cout << WRITECOORDTOATTACK << std::endl;
    std::cin >> coordinateX >> coordinateY;
  }

  return std::make_pair(std::stoi(coordinateX), convertSecondCoordinate(coordinateY));
}

OutType operator!(OutType &type) {
  return (type == OutType::showFirstMap) ? OutType::showSecondMap : OutType::showFirstMap;
}