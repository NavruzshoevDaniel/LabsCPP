#include <iostream>
#include <getopt.h>
#include "Game.h"

void showHelp() {
  std::string line;
  std::ifstream welcomeFile("help.txt");

  system("clear");
  if (welcomeFile.is_open()) {
    while (!welcomeFile.eof()) {
      getline(welcomeFile, line);
      std::cout << line << std::endl;
    }
    welcomeFile.close();
  }
}

int main(int argc, char **argv) {
  const char *shortOptions = "hc:f:s:";

  const struct option longOptions[] = {
      {"help", no_argument, nullptr, 'h'},
      {"count", required_argument, nullptr, 'c'},
      {"first", required_argument, nullptr, 'f'},
      {"second", required_argument, nullptr, 's'},
      {nullptr, 0, nullptr, 0}
  };

  int rez;
  int optionIndex;
  Game game;
  while ((rez = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1) {
    switch (rez) {
      case 'h': {
        showHelp();
        return 0;
      }
      case 'c': {
        int rounds = std::stoi(optarg);
        game.setRounds(rounds);
        break;
      }
      case 'f': {
        game.setTypePlayer1(optarg);
        break;
      }
      case 's': {
        game.setTypePlayer2(optarg);
        break;
      }
      case '?': {
        std::cout << "Вы явно делаете что-то не так!" << std::endl;
        std::cout << "Воспользуйтесь --help или -h" << std::endl;

        return 0;
      }

      default:break;
    }
  }

  try {
    game.play();
  }
  catch (std::string &ex) {
    std::cout << ex << std::endl;
  }

  return 0;
}