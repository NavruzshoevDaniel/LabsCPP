//
// Created by Daniel on 30/10/2019.
//

#include "Parser.h"

bool Parser::is_number(const string &s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it)) ++it;
  return !s.empty() && it == s.end();
}

void Parser::parse(string &path) {
  ifstream fin;
  fin.open(path);
  this->path = path;
  string buf, id, block;

  int checkId[255] = {0};

  if (fin.is_open()) {

    getline(fin, buf);
    if (buf != "desc")
      throw string("Wrong input");

    while (getline(fin, buf) && fin.good() && (buf != "csed")) {
      istringstream bufStream(buf);
      istream_iterator<string> begin(bufStream);
      istream_iterator<string> end;
      vector<string> words(begin, end);
      //if (!checkInput(checkId, words)) throw string("Wrong input");
      if(words[1]!="=") throw string("Wrong input");

      id = words[0];
      if ((!is_number(id)) || (checkId[atoi(id.c_str())] >= 1)) throw string("Wrong input");
      else checkId[atoi(id.c_str())]++;

      block = words[2];
      words.erase(words.begin(), words.begin() + 3);
      table.insert(pair<string, pair<string, vector<string>>>(id, make_pair(block, words)));
    }

    if (fin.good() && getline(fin, buf)) {
      istringstream bufStream(buf);
      istream_iterator<string> begin(bufStream);
      istream_iterator<string> end;
      vector<string> strOrder(begin, end);

      //if (!checkOder(strOrder)) throw string("Wrong input");

      for (auto &elem:strOrder) {
        if (is_number(elem))
          order.push_back(elem);
      }
    }
  } else throw string("No such file");
  fin.close();
}

WorkFTable Parser::getTable() {
  return this->table;
}

vector<string> Parser::getOrder() {
  return this->order;
}


