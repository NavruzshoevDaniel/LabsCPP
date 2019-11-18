//
// Created by Daniel on 30/10/2019.
//

#include <iostream>
#include "WorkFlow.h"
#include <list>

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

  std::list<shared_ptr<Worker>> lstExecut;

  for (auto &elem: oder) {
    shared_ptr<Worker> block = (BlockFactory::Instance().create(table[elem].first, table[elem].second));
    lstExecut.push_back(block);
  }

  std::string text = "";
  unsigned int countOperation = 0;
  for (auto &elem: lstExecut) {
    if ((countOperation == 0) && elem->getType() == WorkerType::IN) {
      text = table[oder[0]].second[0];
      text = elem->execute(text);
    } else if ((countOperation == (lstExecut.size() - 1)) && elem->getType() == WorkerType::OUT)
      text = elem->execute(text);
    else if (elem->getType() == WorkerType::INOUT)
      text = elem->execute(text);
    else throw string("Wrong oder");

    countOperation++;
  }

}

