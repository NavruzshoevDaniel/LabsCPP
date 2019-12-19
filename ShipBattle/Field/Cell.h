//
// Created by Daniel on 04/12/2019.
//

#ifndef SHIPBATTLE_CELL_H
#define SHIPBATTLE_CELL_H


enum statusCell {
  notShip,
  soloShip,
  doubleShip,
  tripleShip,
  quadrupleShip,
  killedShip,
  notToAdd,
  missOrArea
};

class Cell {
 private:
  statusCell status;
 public:
  Cell();
  statusCell getStatus();
  void setStatus(statusCell newStatus);
};

#endif //SHIPBATTLE_CELL_H
