//
// Created by Daniel on 30/10/2019.
//

#include <iostream>
#include "WorkFlow.h"

void WorkFlow::launch(std::string path) {

  Parser parser;
  try {
    parser.parse(path);
  }
  catch (std::string &ex) {
    throw string(ex);
  }

  WorkFTable table = parser.getTable();
  std::vector<string> oder = parser.getOrder();
  if (!checkTable(table,oder)) throw string("Wrong input");
  BlockFactory factory;
  std::string text = table[oder[0]].second[0];

    for (auto &elem: oder) {
      Worker *block = (BlockFactory::Instance().create(table[elem].first, table[elem].second));
      text = block->execute(text);
    }

}

bool WorkFlow::checkTable(WorkFTable &workFTable, vector<string> &oder) {

  for (auto &elem: workFTable)
    if (!checkBlock(elem.second.first, elem.second.second)) return false;

  if (!checkOder(oder, workFTable)) return false;

  return true;
}

bool WorkFlow::checkBlock(string block, vector<string> &param) {

  int paramCount = param.size();
  if (((block == "readfile" || block == "writefile" || block == "grep" || block == "dump") && paramCount == 1)
      || ((block == "replace") && paramCount == 2)
      || ((block == "sort") && paramCount == 0))
    return true;
  else return false;
}

bool WorkFlow::checkOder(vector<string> &oder, WorkFTable &table) {
  string firstBlock = oder[0];
  string lastBlock = oder[oder.size() - 1];
  if ((table[firstBlock].first == "readfile") && (table[lastBlock].first == "writefile"))
    return true;
  return false;
}
