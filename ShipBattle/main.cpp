#include <iostream>
#include <getopt.h>
//#include "IGamer.h"
#include "Game.h"
using namespace std;

int main(int argc, char **argv) {
  const char *shortOptions = "hc:f:s:";

  const struct option longOptions[] = {
      {"help", no_argument, nullptr, 'h'},
      {"count", required_argument, nullptr, 'c'},
      {"first", optional_argument, nullptr, 'f'},
      {"second", optional_argument, nullptr, 's'},
      {nullptr, 0, nullptr, 0}
  };

  int rez;
  int optionIndex;

  /*while ((rez = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1) {
    switch (rez) {
      case 'h': {
        std::cout << "h" << std::endl;
        break;
      }
      case 'c': {
        std::cout << "c" << std::endl;
        std::cout << optarg << std::endl;

        break;
      }
      case 'f': {
        std::cout << "f" << std::endl;
        std::cout << optarg << std::endl;
        break;
      }
      case 's': {
        std::cout << "s" << std::endl;
        std::cout << optarg << std::endl;
        break;
      }
      case '?':{
        std::cout << "Вы явно делаете что-то не так!"<<std::endl;
        std::cout << "Воспользуйтесь --help или -h"<<std::endl;

        return 0;
      }


      default:break;
    }
  }*/
 Game game;
 game.play();
  return 0;
}