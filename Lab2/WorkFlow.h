//
// Created by Daniel on 30/10/2019.
//

#ifndef LAB2_WORKFLOW_H
#define LAB2_WORKFLOW_H

#include <cstdio>
#include <string>
#include "Parser.h"
#include "Factory/BlockFactory.h"
class WorkFlow {
 private:
  bool checkOder (vector<string> &oder,WorkFTable &table);
  bool checkBlock (string block, vector<string> &param);
  bool checkTable(WorkFTable &workFTable,vector<string> &oder);
 public:
  void launch(std::string path);

};

#endif //LAB2_WORKFLOW_H
