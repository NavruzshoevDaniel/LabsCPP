//
// Created by Daniel on 21/12/2019.
//

#include "ConsoleGamer.h"

static GamerMaker<ConsoleGamer> consoleG("console");

std::vector<Ship> ConsoleGamer::putShips(Map &playerMap, OutType outType) {
  ConsoleOperations console;
  std::pair<int, int> xyCoord;
  Map map;
  std::string orientation;
  bool checkInMap = false;
  std::vector<Ship> newPlayerShips;

  for (int i = TOTAL_SHIPS; i > 0; --i) {
    for (int j = 0; j <= TOTAL_SHIPS - i; ++j) {
      system("clear");

      if (outType == OutType::showFirstMap)
        console.viewBoard(playerMap, map, outType);
      else
        console.viewBoard(map, playerMap, outType);

      while (!checkInMap) {
        xyCoord = console.readingCoordinates(i);

        if (i != 1)
          orientation = console.readingOrientation(i);

        Ship ship(xyCoord, orientation, i);

        checkInMap = playerMap.putShip(ship);

        if (!checkInMap)
          std::cout << "ERROR:Неправильно поставили корабль(минимальное расстояние между кораблями - 1,"
                       "корабли не должны выходить за границы поля)" << std::endl;
        else
          newPlayerShips.push_back(ship);
      }
      checkInMap = false;

    }
  }
  return newPlayerShips;
}

std::pair<int, int> ConsoleGamer::getCoordToAttack(Map &enemyMap) {

  ConsoleOperations consoleOperations;
  return consoleOperations.readingCoordinatesToAttack();
}

bool ConsoleGamer::isCommunicate() {
  return true;
}