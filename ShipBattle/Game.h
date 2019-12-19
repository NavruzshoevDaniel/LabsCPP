//
// Created by Daniel on 08/12/2019.
//

#ifndef SHIPBATTLE_GAME_H
#define SHIPBATTLE_GAME_H
#include "IGamer.h"
#include <unistd.h>

enum typeGamer{
  consoleGamer,
  randomGamer,
  optimalGamer
};

class Game {
 protected:
  typedef std::vector<Ship> PlayersShips;
  PlayersShips playerShips1;
  PlayersShips playerShips2;
  Map playerMap1;
  Map playerMap2;


  int countWinPlayer1=0;
  int countWinPlayer2=0;
  int rounds = 1;
  bool winner = false;

  void congratsWinner();
  void showStatistics();
  bool attack(PlayersShips &enemyShips, Map &enemyMap,std::pair<int,int> attackCoord);
  bool checkAttack(Map &enemyMap, int x, int y);
  bool transferAnotherPlayer();
  void confirmReadyToStart();
  void transferPutShips();
  void clearBeforeTheNextGame();

  void playersPutShips(IGamer *gamer1,IGamer *gamer2);
  void attacking(IGamer *gamer,PlayersShips &enemyShips, Map &enemyMap, OutType outType);

 public:

  void play();
  void setRounds(int rounds);
  ~Game()= default;

};

#endif //SHIPBATTLE_GAME_H
