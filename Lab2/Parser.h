//
// Created by Daniel on 30/10/2019.
//

#ifndef LAB2_PARSER_H
#define LAB2_PARSER_H

#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
typedef  map<string, pair<string, vector<string>>> WorkFTable;
class Parser {
 private:
  string path;
  WorkFTable table;
  vector<string> order;

  bool is_number(const string &s);
 public:

  void parse(string &path);
  WorkFTable getTable();
  vector<string> getOrder();
};

#endif //LAB2_PARSER_H
