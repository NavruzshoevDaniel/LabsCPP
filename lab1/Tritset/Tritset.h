//
// Created by Daniel on 18.09.2019.
//

#ifndef LAB1_TRITSET_H
#define LAB1_TRITSET_H
#include <unordered_map>
namespace Trits {
using namespace std;

enum trit { False, Unknown, True };

class Tritset {
 private:
  int sizeArr;
  int sizeTrits;
  unsigned *memory;
 public:

  Tritset(int n);
  Tritset(Tritset const  &obj);
  ~Tritset();
  void shrink();

  Tritset &operator~();
  Tritset &operator&(const Tritset &trtSet);
  Tritset &operator|(const Tritset &trtSet);


  int cardinality(trit value);
  void trim(int lastIndex);
  unordered_map< trit, int> cardinality();
  int length();


  class Reference {
   private:
    Tritset *tritSet;
    unsigned *ptr;
    unsigned index;
    unsigned globalIndx;
    bool newMem;
   public:

    Reference(Tritset *tritset, unsigned *arr, unsigned i, unsigned global, bool newMem);
    ~Reference();
    operator trit();
    Reference &operator=(const trit trt);
    Reference &operator=(Reference &ref);
    trit operator~();
    trit operator&(const trit trt);
    trit operator|(const trit trt);
    friend ostream &operator<<(ostream &out,const trit &trt);

  };

  int capasity();
  const trit operator[](const int i) const;
  Reference operator[](const int i);

};
}

#endif //LAB1_TRITSET_H
