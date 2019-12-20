//
// Created by Daniel on 08/12/2019.
//

#include "Game.h"

void Game::play() {

  int countRounds = 0;

  while (rounds != countRounds) {
    IGamer *gamer1 = GamerFactory::Instance().createGamer(typePlayer1);
    IGamer *gamer2 = GamerFactory::Instance().createGamer(typePlayer2);

    playersPutShips(gamer1, gamer2);

    while (!winner) {

      attacking(gamer1, playerShips2, playerMap2, OutType::showFirstMap);

      if (winner) {
        countWinPlayer1++;
        break;
      }

      if (gamer1->isCommunicate() && gamer2->isCommunicate())
        transferAnotherPlayer();

      attacking(gamer2, playerShips1, playerMap1, OutType::showSecondMap);

      if (winner) {
        countWinPlayer2++;
        break;
      }

      if (gamer1->isCommunicate() && gamer2->isCommunicate())
        transferAnotherPlayer();
    }
    congratsWinner();
    countRounds++;
    winner = false;
    clearBeforeTheNextGame();
    delete (gamer1);
    delete (gamer2);
  }
  showStatistics();
}

void Game::playersPutShips(IGamer *gamer1, IGamer *gamer2) {
  playerShips1 = gamer1->putShips(playerMap1, OutType::showFirstMap);
  system("clear");

  if (gamer1->isCommunicate() && gamer2->isCommunicate())
    transferPutShips();
  playerShips2 = gamer2->putShips(playerMap2, OutType::showSecondMap);

  system("clear");
  if (gamer1->isCommunicate() && gamer2->isCommunicate())
    confirmReadyToStart();
}

bool Game::transferAnotherPlayer() {
  std::cout << "Очередь следущего игрока" << std::endl;
  std::cout << "Следующий игрок готов?(если да, напишите 'y')" << std::endl;
  std::string yes;
  while (yes != "y")
    std::cin >> yes;
  return true;
}

void Game::confirmReadyToStart() {
  std::cout << "Игра начинается!" << std::endl;
  std::cout << "Player 1, убери экран от своего противника!" << std::endl;
  std::cout << "Если ты убрал экран, жми 'y' и шмаляй по кораблям!" << std::endl;
  std::string yes;
  while (yes != "y")
    std::cin >> yes;
}

void Game::congratsWinner() {
  if (playerShips1.empty())
    std::cout << "Player 2 ПОБЕДИЛ!" << std::endl;

  if (playerShips2.empty())
    std::cout << "Player 1 ПОБЕДИЛ!" << std::endl;
}

bool Game::attack(PlayersShips &enemyShips, Map &enemyMap, std::pair<int, int> attackCoord) {

  for (auto itShip = enemyShips.begin(); itShip != enemyShips.end();) {
    for (auto itCoord = itShip->getCoordinates().begin(); itCoord != itShip->getCoordinates().end();) {

      if ((itCoord->first == attackCoord.first) && (itCoord->second == attackCoord.second)) {
        enemyMap.getMap()[attackCoord.first][attackCoord.second].setStatus(killedShip);
        itCoord = itShip->getCoordinates().erase(itCoord);

        if (itShip->getCoordinates().empty()) {
          enemyMap.changeAroundArea(*itShip);
          itShip = enemyShips.erase(itShip);
        }

        if (enemyShips.empty()) {
          winner = true;
          return false;
        }

        return true;
      } else
        ++itCoord;
    }
    ++itShip;
  }
  enemyMap.getMap()[attackCoord.first][attackCoord.second].setStatus(missOrArea);
  return false;
}

void Game::attacking(IGamer *gamer, PlayersShips &enemyShips, Map &enemyMap, OutType outType) {

  ConsoleOperations consoleOperations;

  bool playersAttack = true;
  std::pair<int, int> coordToAttack;

  while (playersAttack) {

    consoleOperations.viewBoard(playerMap1, playerMap2, outType);

    coordToAttack = gamer->getCoordToAttack(enemyMap);

    if (!checkAttack(enemyMap, coordToAttack.first, coordToAttack.second)) {
      system("clear");
      if (gamer->isCommunicate())
        std::cout << "Ты уже шмалял по этой клетке,капитан!\nВыбери другие координаты!" << std::endl;

      continue;
    }

    playersAttack = attack(enemyShips, enemyMap, coordToAttack);

    /* if (!gamer->isCommunicate())
       sleep(1);*/
    system("clear");
  }

}

void Game::transferPutShips() {
  std::cout << "Следующий игрок расставляет корабли!" << std::endl;
  std::cout << "Следующий игрок готов?(если да, напишите 'y')" << std::endl;
  std::string yes;
  while (yes != "y")
    std::cin >> yes;
}

bool Game::checkAttack(Map &enemyMap, int x, int y) {
  statusCell status = enemyMap.getMap()[x][y].getStatus();
  return (status != killedShip) && (status != missOrArea);
}

void Game::showStatistics() {
  std::string line;
  std::ifstream welcomeFile("statistics.txt");

  if (welcomeFile.is_open()) {
    while (!welcomeFile.eof()) {
      getline(welcomeFile, line);
      std::cout << line << std::endl;
    }
    welcomeFile.close();
  }
  std::cout << "-\t" << std::setw(10) << countWinPlayer1 << "\t\t   -\t\t" << std::setw(7) << countWinPlayer2
            << "\t\t\t -" << std::endl;
  std::cout << "--------------------------------------------------------------------------" << std::endl;
}

void Game::clearBeforeTheNextGame() {
  playerMap1.clearMap();
  playerMap2.clearMap();
  playerShips1.clear();
  playerShips2.clear();
}

void Game::setRounds(int rounds) {
  this->rounds = rounds;
}

void Game::setTypePlayer1(char *typePlayer) {
  this->typePlayer1=typePlayer;
}

void Game::setTypePlayer2(char *typePlayer) {
  this->typePlayer2=typePlayer;
}
