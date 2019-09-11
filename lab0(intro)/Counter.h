#include <iostream>
#include <vector>
#include "string"
#include "fstream"
#include "map"

namespace Counter {

using namespace std;

class Freq {
 private:
  ifstream fin;
  ofstream fout;
  int counter;
  string str;
  map<string, int> words;
  vector<pair<int, string> > arr_words;

  void partition();

  void addWordInMap(string str);

  void sortMapFreq();

 public:
  Freq(string infile, string outfile);

  ~Freq();

  void outFreq();
};
}
