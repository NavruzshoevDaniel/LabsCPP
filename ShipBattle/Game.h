//
// Created by Daniel on 08/12/2019.
//

#ifndef SHIPBATTLE_GAME_H
#define SHIPBATTLE_GAME_H
#include "Gamers/IGamer.h"
#include "Gamers/RandomGamer.h"
#include "Gamers/ConsoleGamer.h"
#include "Gamers/OptimalGamer.h"
#include "Factory/GamerFactory.h"

class Game {
 private:
  typedef std::vector<Ship> PlayersShips;
  PlayersShips playerShips1;
  PlayersShips playerShips2;
  Map playerMap1;
  Map playerMap2;
  std::string typePlayer1="random";
  std::string typePlayer2="random";
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
  void setTypePlayer1(char *typePlayer);
  void setTypePlayer2(char *typePlayer);

  ~Game()= default;

};

#endif //SHIPBATTLE_GAME_H
