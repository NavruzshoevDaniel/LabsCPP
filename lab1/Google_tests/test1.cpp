//
// Created by Daniel on 29/09/2019.
//


#include "gtest/gtest.h"

#include "Tritset.h"
#include "BitManipulationForTrit.h"
using namespace Trits;
using namespace BitManipulation;


TEST(Test_1, TestSetValue) {
  Tritset tritset(30);

  trit trt = tritset[20];
  //Unknown value
  ASSERT_EQ(trt, Unknown);
  //True value
  tritset[20]=True;
  trt = tritset[20];
  ASSERT_EQ(trt, True);
  //False value
  tritset[20]=False;
  trt = tritset[20];
  ASSERT_EQ(trt, False);
}

TEST(Test_2,TestCapasityAndLength){
  Tritset trtset1(36);
  Tritset trtset2(10);
  Tritset trtset3(20);
  ASSERT_EQ(trtset1.length(),36);
  ASSERT_EQ(trtset1.capasity(),3);
  ASSERT_EQ(trtset2.length(),10);
  ASSERT_EQ(trtset2.capasity(),1);
  ASSERT_EQ(trtset3.length(),20);
  ASSERT_EQ(trtset3.capasity(),2);

}

TEST(Test_3,TestShrink){
  Tritset trtset(20);

  for (int i = 0; i < 8; ++i) {
    trtset[i]=True;
  }

  for (int i = 8; i < 15; ++i) {
    trtset[i]=False;
  }
  trtset.shrink();
  ASSERT_EQ(trtset.length(),15);
  ASSERT_EQ(trtset.capasity(),1);
  for (int i = 8; i < 15; ++i) {
    trtset[i]=Unknown;
  }
  trtset.shrink();
  ASSERT_EQ(trtset.length(),8);
}


TEST(Test_4,TestNewMem){
  Tritset trtset(20);
  trtset[21]=True;
  ASSERT_EQ(trtset.length(),21);
  trtset[50]=True;
  ASSERT_EQ(trtset.length(),50);
  trit trt=trtset[50];
  ASSERT_EQ(trt,True);

}

TEST(Test_5,TestNot) {
  Tritset trtset1(20);
  Tritset trtset2(10);

  trtset1[1] = True;
  trtset1[2] = False;
  trtset2[1] = ~trtset1[1];
  trtset2[2] = ~trtset1[2];
  trtset2[3] = ~trtset1[3];

  trit trt=trtset2[1];
  ASSERT_EQ(trt,False);
  trt=trtset2[2];
  ASSERT_EQ(trt,True);
  trt=trtset2[3];
  ASSERT_EQ(trt,Unknown);
  for (int i = 0; i <3; ++i) {
    trtset1[i]=True;
  }
  for (int i = 3; i <=6; ++i) {
    trtset1[i]=False;
  }

  trtset2=~trtset1;
 for (int i = 0; i <3; ++i) {
    trt=trtset2[i];
    ASSERT_EQ(trt,False);
  }
  for (int i = 3; i <=6; ++i) {
    trt=trtset2[i];
    ASSERT_EQ(trt,True);
  }

}

TEST(Test_6,TestOr){
  Tritset trtset1(20);
  Tritset trtset2(10);
  Tritset trtset3(15);

  trtset1[1] = True;
  trtset1[2] = False;
  trtset2[1] = False;
  trtset2[2] = False;


  trtset3[1]=trtset1[1]|trtset2[1];
  trit trt=trtset3[1];
  ASSERT_EQ(trt,True);

  trtset3[2]=trtset1[2]|trtset2[2];
  trt=trtset3[2];
  ASSERT_EQ(trt,False);

  trtset3[2]=trtset1[1]|trtset1[1];
  trt=trtset3[2];
  ASSERT_EQ(trt,True);

  trtset3[3]=trtset1[1]|trtset2[3];
  trt=trtset3[3];
  ASSERT_EQ(trt,True);

  for (int i = 0; i < 3; ++i) {
    trtset1[i]=True;
    trtset2[i]=False;
  }
  trtset1[3]=True;
  trtset2[3]=True;
  trtset1[4]=False;
  trtset2[4]=False;
  trtset1[5]=True;
  trtset1[6]=False;
  trtset3=trtset1|trtset2;
  for (int j = 0; j < 3; ++j) {
    trt=trtset3[j];
    ASSERT_EQ(trt,True);
  }
  trt=trtset3[4];
  ASSERT_EQ(trt,False);
  trt=trtset3[5];
  ASSERT_EQ(trt,True);
  trt=trtset3[6];
  ASSERT_EQ(trt,Unknown);

}

TEST(Test_7,TestAnd){
  Tritset trtset1(20);
  Tritset trtset2(10);
  Tritset trtset3(15);

  trtset1[1] = True;
  trtset1[2] = False;
  trtset2[1] = False;
  trtset2[2] = False;


  trtset3[1]=trtset1[1]&trtset2[1];
  trit trt=trtset3[1];
  ASSERT_EQ(trt,False);

  trtset3[2]=trtset1[2]&trtset2[2];
  trt=trtset3[2];
  ASSERT_EQ(trt,False);

  trtset3[2]=trtset1[1]&trtset1[1];
  trt=trtset3[2];
  ASSERT_EQ(trt,True);

  trtset3[3]=trtset1[1]&trtset2[3];
  trt=trtset3[3];
  ASSERT_EQ(trt,Unknown);

  for (int i = 0; i < 3; ++i) {
    trtset1[i]=True;
    trtset2[i]=False;
  }
  trtset1[3]=True;
  trtset2[3]=True;
  trtset1[4]=False;
  trtset2[4]=False;
  trtset1[5]=True;
  trtset1[6]=False;
  trtset1[12]=True;
  trtset3=trtset1&trtset2;
 for (int j = 0; j < 3; ++j) {
    trt=trtset3[j];
    ASSERT_EQ(trt,False);
  }
  trt=trtset3[4];
  ASSERT_EQ(trt,False);
  trt=trtset3[5];
  ASSERT_EQ(trt,Unknown);
  trt=trtset3[6];
  ASSERT_EQ(trt,False);
}

TEST(Test_8,TestCardinality){
  Tritset trtset(20);
  for (int i = 0; i <5; ++i)
    trtset[i]=True;
  for (int j = 5; j < 13; ++j)
    trtset[j]=False;
  int t=trtset.cardinality(True);
  int f=trtset.cardinality(False);
  int u=trtset.cardinality(Unknown);
  ASSERT_EQ(t,5);
  ASSERT_EQ(f,8);
  ASSERT_EQ(u,7);
}

TEST(Test_9,TestTrim){
  Tritset trtset(20);
  for (int i = 0; i <20; ++i)
    trtset[i]=True;
  trtset.trim(10);
  trit trt;
  for (int j = 10; j <20 ; ++j) {
    trt=trtset[j];
    ASSERT_EQ(trt,Unknown);
  }
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
