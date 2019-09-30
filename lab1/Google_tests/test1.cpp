//
// Created by Daniel on 29/09/2019.
//


#include "gtest/gtest.h"

#include "Tritset.h"
#include "BitManipulationForTrit.h"
using namespace Trits;
using namespace BitManipulation;
TEST(TestCaseName, TestName) {
  Tritset tritset(100);
  trit  trt=tritset[1000];
  ASSERT_EQ(trt, Unknown);

}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


