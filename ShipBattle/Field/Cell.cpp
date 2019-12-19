//
// Created by Daniel on 04/12/2019.
//

#include "Cell.h"

Cell::Cell() {
  this->status=notShip;
}

statusCell Cell::getStatus() {
  return this->status;
}

void Cell::setStatus(statusCell newStatus) {
  this->status=newStatus;
}
