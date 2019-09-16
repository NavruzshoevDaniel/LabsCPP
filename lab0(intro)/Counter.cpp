#include "Counter.h"

namespace Counter {

void Freq::partition() {
  string word = "";
  while (getline(fin, str)) {
    for (char c : str) {
      if (isdigit(c) || isalpha(c))
        word += c;
      else {
        addWordInMap(word);
        word = "";
      }

    }
    if (word != "")
      addWordInMap(word);
    word = "";
  }
}
void Freq::addWordInMap(string str) {
  counter++;
  if (words.find(str) == words.end())
    words.emplace(str, 1);
  else
    words.find(str)->second++;
}

void Freq::sortMapFreq() {

  for (auto &obj:words) {
    arr_words.push_back(make_pair(obj.second, obj.first));
  }
  sort(arr_words.begin(), arr_words.end());
  reverse(begin(arr_words), end(arr_words));
}

Freq::Freq(string infile, string outfile) {
    counter = 0;
    fin.open(infile);
    fout.open(outfile);
}
Freq::~Freq() {
  fin.close();
  fout.close();
}

void Freq::outFreq() {
  partition();
  sortMapFreq();
  for (auto &obj: arr_words) {
    fout << obj.second << ";" << obj.first << ";" << obj.first / (float) counter * 100 << endl;
  }

}

}
