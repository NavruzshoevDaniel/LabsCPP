cmake_minimum_required(VERSION 3.12)
project(ShipBattle)

set(CMAKE_CXX_STANDARD 14)

add_executable(ShipBattle main.cpp Field/Ship.cpp Field/Ship.h Console/ConsoleOperations.cpp Console/ConsoleOperations.h Field/Cell.cpp Field/Cell.h Field/Map.cpp Field/Map.h Gamers/IGamer.h StringResources.h Game.cpp Game.h Factory/GamerFactory.cpp Factory/GamerFactory.h Factory/IGamerMaker.h Factory/GamerMaker.h Gamers/OptimalGamer.cpp Gamers/OptimalGamer.h Gamers/RandomGamer.cpp Gamers/RandomGamer.h Gamers/ConsoleGamer.cpp Gamers/ConsoleGamer.h)