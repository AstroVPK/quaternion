#include <cmath>
#include <complex>
#include <limits>
#include <list>
#include <cstdint>
#include <iostream>
#include <typeinfo>

#include "gtest/gtest.h"
#include "quaternion.hpp"


template <typename T>
class QuaternionTests : public testing::Test {
 public:
  algebra::quaternion<T> q;

  void SetUp(const T& i, const T& j, const T& k, const T& l) {
    this->q = algebra::quaternion(i, j, k, l);
  }

  template <typename I, typename J, typename K, typename L>
  void SetUp(I const & i, J const & j, K const & k, L const & l) {
    this->q = algebra::quaternion<T>(i, j, k, l);
  }
};

using MyTypes = ::testing::Types<char, short, int, long, float, double>;

TYPED_TEST_SUITE(QuaternionTests, MyTypes);

TYPED_TEST(QuaternionTests, ValueInitialization) {
  EXPECT_EQ(this->q.a, 0);
  EXPECT_EQ(this->q.b, 0);
  EXPECT_EQ(this->q.c, 0);
  EXPECT_EQ(this->q.d, 0);
}

TYPED_TEST(QuaternionTests, DirectInitialization00) {
  int i = 5, j = 235, k = 67, l = 82;
  this->SetUp(i, j, k, l);
  if (static_cast<TypeParam>(i) == i) {
    EXPECT_EQ(this->q.a, i);
  }
  if (static_cast<TypeParam>(j) == j) {
    EXPECT_EQ(this->q.b, j);
  }
  if (static_cast<TypeParam>(k) == k) {
    EXPECT_EQ(this->q.c, k);
  }
  if (static_cast<TypeParam>(l) == l) {
    EXPECT_EQ(this->q.d, l);
  }
}

TYPED_TEST(QuaternionTests, SecondDirectInitialization01) {
  int i = 5;
  float j = 19168720229.277867697987;
  short k = -235;
  double l = -2.6;
  this->SetUp(i, j, k, l);
  if (static_cast<TypeParam>(i) == i) {
    EXPECT_EQ(this->q.a, i);
  }
  if (static_cast<TypeParam>(j) == j) {
    EXPECT_EQ(this->q.b, j);
  }
  if (static_cast<TypeParam>(k) == k) {
    EXPECT_EQ(this->q.c, k);
  }
  if (static_cast<TypeParam>(l) == l) {
    EXPECT_EQ(this->q.d, l);
  }
}


#define TEST_IN_PLACE_TYPED_TEST(TYPE)               \
TYPED_TEST(QuaternionTests, AddInPlace_##TYPE) {     \
  int i = 1, j = 2, k = 3, l = 4;                    \
  this->SetUp(i, j, k, l);                           \
  TYPE a = 1;                                        \
  this->q += a;                                      \
  EXPECT_EQ(this->q.a, i + a);                       \
}                                                    \
                                                     \
TYPED_TEST(QuaternionTests, SubInPlace_##TYPE) {     \
  int i = 1, j = 2, k = 3, l = 4;                    \
  this->SetUp(i, j, k, l);                           \
  TYPE a = 1;                                        \
  this->q -= a;                                      \
  EXPECT_EQ(this->q.a, i - a);                       \
}                                                    \
                                                     \
TYPED_TEST(QuaternionTests, SMultInPlace_##TYPE) {   \
  int i = 1, j = 2, k = 3, l = 4;                    \
  this->SetUp(i, j, k, l);                           \
  TYPE r = 1;                                        \
  this->q *= r;                                      \
  EXPECT_EQ(this->q.a, i*r);                         \
  EXPECT_EQ(this->q.b, j*r);                         \
  EXPECT_EQ(this->q.c, k*r);                         \
  EXPECT_EQ(this->q.d, l*r);                         \
}

TEST_IN_PLACE_TYPED_TEST(char)

TEST_IN_PLACE_TYPED_TEST(short)

TEST_IN_PLACE_TYPED_TEST(int)

TEST_IN_PLACE_TYPED_TEST(long)

TEST_IN_PLACE_TYPED_TEST(float)

TEST_IN_PLACE_TYPED_TEST(double)

int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}
