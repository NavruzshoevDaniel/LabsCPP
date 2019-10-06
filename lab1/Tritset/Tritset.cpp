//
// Created by Daniel on 18.09.2019.
//
#include <cmath>
#include <cstring>
#include <iostream>
#include "Tritset.h"
#include "BitManipulationForTrit.h"

namespace Trits {

Tritset::Tritset(int n) {
  sizeTrits = n;
  sizeArr = (int) (ceil(n * 2 / (float) 8 / (float) sizeof(unsigned)));
  memory = new unsigned[sizeArr];
  memset(memory, 0, sizeArr * sizeof(unsigned));
}

Tritset::Tritset(Tritset const &obj) {
  sizeArr = obj.sizeArr;
  sizeTrits = obj.sizeTrits;
  memory = new unsigned[sizeArr];
  memset(memory, 0, sizeArr * sizeof(unsigned));
  memcpy(memory, obj.memory, obj.sizeArr * sizeof(unsigned));
}

Tritset::~Tritset() {
  delete[] memory;
}

Tritset::Reference Tritset::operator[](const int i) {

    int tmp = (int) (ceil(i * 2 / (float) 8 / (float) sizeof(unsigned)));

    if (tmp > sizeArr) {
      unsigned *newMemory;
      newMemory = new unsigned(0);
      return Reference(this, newMemory, i % (4 * sizeof(unsigned)), i, true);
    }

  return Reference(this, memory, i % (4 * sizeof(unsigned)), i, false);
}

const trit Tritset::operator[](const int i) const {
  return BitManipulation::getITrit(&memory[i / (sizeof(unsigned) * 4)], i % (sizeof(unsigned) * 4));
}

int Tritset::capasity() {
  return sizeArr;
}

void Tritset::shrink() {

  int newSize = sizeArr;

  while ((memory[newSize - 1] == 0) && (newSize > 1)) {
    newSize--;
  }
  int i = 16;
  sizeTrits = newSize * 16 +1;
  while (i > 1) {
    if (BitManipulation::getITrit(&memory[newSize - 1], i) == Unknown)
      sizeTrits--;
    else break;
    i--;
  }
  if (newSize != sizeArr) {
    unsigned *newMemory;
    newMemory = new unsigned[newSize];
    memset(newMemory, 0, newSize * sizeof(unsigned));
    memcpy(newMemory, memory, sizeArr * sizeof(unsigned));
    sizeArr = newSize;
    delete[] memory;
    memory = newMemory;
  }

}
//TritsetOperations
Tritset &Tritset::operator~() {
  Tritset *newTritset = new Tritset(sizeTrits);

  trit trt = Unknown;
  for (int i = 0; i < sizeTrits; ++i) {
    trt = BitManipulation::getITrit(&this->memory[i / (sizeof(unsigned) * 4)], i % (sizeof(unsigned) * 4));
    (*newTritset)[i] = BitManipulation::notOperation(trt);
  }

  return *newTritset;
}

Tritset &Tritset::operator&(const Tritset &trtSet) {
  int newSizeTrits = 0;
  Tritset *newTritset = new Tritset(newSizeTrits);

  this->sizeTrits >= trtSet.sizeTrits ? newTritset->sizeTrits = sizeTrits : newTritset->sizeTrits = trtSet.sizeTrits;

  newSizeTrits = newTritset->sizeTrits;
  trit trt1 = Unknown;
  trit trt2 = Unknown;

  for (int i = 0; i < newSizeTrits; ++i) {
    trt1 = (*this)[i];
    trt2 = (trtSet)[i];
    (*newTritset)[i] = BitManipulation::andOperation(trt1, trt2);
  }
  return *newTritset;
}

Tritset &Tritset::operator|(const Tritset &trtSet) {
  int newSizeTrits = 0;
  Tritset *newTritset = new Tritset(newSizeTrits);

  this->sizeTrits >= trtSet.sizeTrits ? newTritset->sizeTrits = sizeTrits : newTritset->sizeTrits = trtSet.sizeTrits;

  newSizeTrits = newTritset->sizeTrits;
  trit trt1 = Unknown;
  trit trt2 = Unknown;

  for (int i = 0; i < newSizeTrits; ++i) {
    trt1 = (*this)[i];
    trt2 = (trtSet)[i];
    (*newTritset)[i] = BitManipulation::orOperation(trt1, trt2);
  }
  return *newTritset;
}

ostream &operator<<(std::ostream &out, Tritset &trtSet) {

  for (int i = 0; i < trtSet.length(); ++i) {
    out<<BitManipulation::getStrTrit(trtSet[i])<<" ";
  }

  return out;
}

//Print trit
ostream &operator<<(ostream &out, const trit &trt) {
  out<< BitManipulation::getStrTrit(trt)<<endl;
  return out;
}

//Additional functions for Tritset
int Tritset::cardinality(trit value) {
  int count = 0;
  for (int i = 0; i < sizeTrits; ++i)
    if((*this)[i] == value)
      count++;
  return count;
}

void Tritset::trim(int lastIndex) {
  for (int i = lastIndex; i <sizeTrits; ++i)
    (*this)[i]=Unknown;
}

int Tritset::length() {
  if((sizeArr==1) && (memory[0]==0))
    return 0;
  return sizeTrits;
}

unordered_map<trit, int> Tritset::cardinality() {
  unordered_map<trit, int> *map;
  map = new unordered_map<trit, int>;
  map->insert(make_pair(True,cardinality(True)));
  map->insert(make_pair(False,cardinality(False)));
  map->insert(make_pair(Unknown,cardinality(Unknown)));
  return *map;
}

//ReferenceFunctions
Tritset::Reference::Reference(Tritset *tritset, unsigned *arr, unsigned i, unsigned global, bool newMem) {
  this->tritSet = tritset;
  ptr = arr;
  index = i;
  globalIndx = global;
  this->newMem = newMem;
}

Tritset::Reference &Tritset::Reference::operator=(const trit trt) {
  if (newMem)
    BitManipulation::setITrit(ptr, trt, index % (sizeof(unsigned) * 4));
  else
    BitManipulation::setITrit(&ptr[globalIndx / (sizeof(unsigned) * 4)], trt, index % (sizeof(unsigned) * 4));
  return *this;
}

Tritset::Reference::operator trit() {
  return BitManipulation::getITrit(&ptr[globalIndx / (sizeof(unsigned) * 4)], index % (sizeof(unsigned) * 4));
}

Tritset::Reference::~Reference() {

  int tmp = (int) (ceil(globalIndx * 2 / (float) 8 / (float) sizeof(unsigned)));

  if(globalIndx>tritSet->sizeTrits)
    tritSet->sizeTrits = globalIndx;

  if (newMem && (*ptr != 0)) {
    unsigned *newMemory;
    newMemory = new unsigned[tmp];
    memset(newMemory, 0, tmp * sizeof(unsigned));
    newMemory[tmp - 1] = *ptr;
    memcpy(newMemory, tritSet->memory, tritSet->sizeArr * sizeof(unsigned));
    tritSet->sizeArr = tmp;
    delete[] tritSet->memory;
    tritSet->memory = newMemory;
  }

}

//Ref Operations
trit Tritset::Reference::operator~() {
  trit trt = BitManipulation::getITrit(&ptr[globalIndx / (sizeof(unsigned) * 4)], index % (sizeof(unsigned) * 4));
  trit notTrt = BitManipulation::notOperation(trt);
  return notTrt;
}

trit Tritset::Reference::operator&(const trit trt2) {
  trit trt1 = BitManipulation::getITrit(&ptr[globalIndx / (sizeof(unsigned) * 4)], index % (sizeof(unsigned) * 4));
  trit andTrt = BitManipulation::andOperation(trt1, trt2);
  return andTrt;
}

trit Tritset::Reference::operator|(const trit trt2) {
  trit trt1 = BitManipulation::getITrit(&ptr[globalIndx / (sizeof(unsigned) * 4)], index % (sizeof(unsigned) * 4));
  trit orTrt = BitManipulation::orOperation(trt1, trt2);
  return orTrt;
}

Tritset::Reference &Tritset::Reference::operator=(Tritset::Reference &ref) {

  return *this;
}


}