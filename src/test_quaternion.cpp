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
}

TEST_IN_PLACE_TYPED_TEST(char)

TEST_IN_PLACE_TYPED_TEST(short)

TEST_IN_PLACE_TYPED_TEST(int)

TEST_IN_PLACE_TYPED_TEST(long)

TEST_IN_PLACE_TYPED_TEST(float)

TEST_IN_PLACE_TYPED_TEST(double)

int main(int argc, char **argv) {

  /*
  std::cout << "Default constructing a quaternion" << std::endl;
  algebra::quaternion<int> a_quaternion;
  std::cout << a_quaternion << std::endl;

  std::cout << "Constructing a quaternion using the first constructor" << std::endl;
  algebra::quaternion<int> b4_quaternion(1, 2, 3, 4);
  std::cout << b4_quaternion << std::endl;

  std::cout << "Constructing a quaternion using the first constructor" << std::endl;
  algebra::quaternion<int> b3_quaternion(1, 2, 3);
  std::cout << b3_quaternion << std::endl;

  std::cout << "Constructing a quaternion using the first constructor" << std::endl;
  algebra::quaternion<int> b2_quaternion(1, 2);
  std::cout << b2_quaternion << std::endl;

  std::cout << "Constructing a quaternion using the first constructor" << std::endl;
  algebra::quaternion<int> b1_quaternion(1);
  std::cout << b1_quaternion << std::endl;

  int i = 1;
  long j = 2;
  float k = 3.5;
  uint l = 4;

  std::cout << "Constructing a quaternion using the second constructor" << std::endl;
  algebra::quaternion<double> c4_quaternion(i, j, k, l);
  std::cout << c4_quaternion << std::endl;

  std::cout << "Constructing a quaternion using the second constructor" << std::endl;
  algebra::quaternion<double> c3_quaternion(i, j, k);
  std::cout << c3_quaternion << std::endl;

  std::cout << "Constructing a quaternion using the second constructor" << std::endl;
  algebra::quaternion<double> c2_quaternion(i, j);
  std::cout << c2_quaternion << std::endl;

  std::cout << "Constructing a quaternion using the second constructor" << std::endl;
  algebra::quaternion<double> c1_quaternion(i);
  std::cout << c1_quaternion << std::endl;

  std::cout << "Constructing a complex<float>" << std::endl;
  std::complex<float> d1_complex(1.7, 2.3);
  std::cout << d1_complex << std::endl;

  std::cout << "Constructing a quaternion<double> from the complex<float>" << std::endl;
  algebra::quaternion<double> d1_quaternion(d1_complex);
  std::cout << d1_quaternion << std::endl;

  std::cout << "Constructing a complex<double>" << std::endl;
  std::complex<double> e1_complex(1.6, 2.4);
  std::cout << e1_complex << std::endl;

  std::cout << "Constructing a quaternion<int> from the complex<double>" << std::endl;
  algebra::quaternion<int> e4_quaternion(e1_complex);
  std::cout << e4_quaternion << std::endl;

  algebra::quaternion<double> f4_quaternion(1.33, 7.67, -6.2, -7.2);
  algebra::quaternion<double> g4_quaternion(9.56, -2.56, -4.92, 8.21);

  std::cout << "Adding two quaternions of the same type" << std::endl;
  algebra::quaternion<double> h4_quaternion = f4_quaternion + g4_quaternion;
  std::cout << f4_quaternion << " + " << g4_quaternion << " = " << h4_quaternion << std::endl;

  std::cout << "Subtracting two quaternions of the same type" << std::endl;
  algebra::quaternion<double> i4_quaternion = f4_quaternion - g4_quaternion;
  std::cout << f4_quaternion << " - " << g4_quaternion << " = " << i4_quaternion << std::endl;

  std::cout << "Adding four quaternions of the same type" << std::endl;
  algebra::quaternion<double> j4_quaternion = f4_quaternion + g4_quaternion + h4_quaternion + i4_quaternion;
  std::cout << f4_quaternion << " + " << g4_quaternion << " + " << h4_quaternion << " + " << i4_quaternion << " = " << j4_quaternion << std::endl;

  std::cout << "Subtracting four quaternions of the same type" << std::endl;
  algebra::quaternion<double> k4_quaternion = f4_quaternion - g4_quaternion - h4_quaternion - i4_quaternion;
  std::cout << f4_quaternion << " - " << g4_quaternion << " - " << h4_quaternion << " - " << i4_quaternion << " = " << k4_quaternion << std::endl;

  std::cout << "Adding a quaternion to a quaternion of the same type" << std::endl;
  algebra::quaternion<double> l4_quaternion(i, j, k, l);
  std::cout << "l4_quaternion: " << l4_quaternion << std::endl;
  std::cout << l4_quaternion << " += " << f4_quaternion;
  l4_quaternion += f4_quaternion;
  std::cout << " = " << l4_quaternion << std::endl;

  std::cout << "Subtracting a quaternion from a quaternion of the same type" << std::endl;
  algebra::quaternion<double> m4_quaternion(i, j, k, l);
  std::cout << "m4_quaternion: " << m4_quaternion << std::endl;
  std::cout << m4_quaternion << " -= " << f4_quaternion;
  m4_quaternion -= f4_quaternion;
  std::cout << " = " << m4_quaternion << std::endl;

  std::cout << "Getting the real part of k4_quaternion" << std::endl;
  std::cout << "k4_quaternion.real() == " << k4_quaternion.real() << std::endl;

  std::cout << "Setting the real part of k4_quaternion = 0" << std::endl;
  k4_quaternion.real(0.0);
  std::cout << "k4_quaternion.real() == " << k4_quaternion.real() << std::endl;

  std::cout << "Getting the imaginary part of k4_quaternion" << std::endl;
  std::array<double, 3> k4_imaginary = k4_quaternion.imag();
  std::cout << "k4_quaternion.imag() == (" << k4_imaginary[0] << "," << k4_imaginary[1] << "," << k4_imaginary[2] << ")" << std::endl;

  std::cout << "Setting the imaginary part of k4_quaternion = (0, 0, 0)" << std::endl;
  k4_quaternion.imag(std::array<double, 3>{0.0, 0.0, 0.0});
  k4_imaginary = k4_quaternion.imag();
  std::cout << "k4_quaternion.imag() == (" << k4_imaginary[0] << "," << k4_imaginary[1] << "," << k4_imaginary[2] << ")" << std::endl;

  std::cout << "The largest value that a component of quaternion<double> can hold is " << std::numeric_limits<algebra::quaternion<double>::value_type>::max() << std::endl;

  std::cout << "m4_quaternion + 5 = " << m4_quaternion + 5 << std::endl;
  std::cout << "e1_quaternion + 5.63d = " << e4_quaternion + 5.63d << std::endl;

  std::cout << "4 + m4_quaternion = " << 4 + m4_quaternion << std::endl;
  std::cout << "6.23d + e1_quaternion = " << 6.23d + e4_quaternion << std::endl;

  std::cout << "m4_quaternion - 5 = " << m4_quaternion - 5 << std::endl;
  std::cout << "e1_quaternion - 5.63d = " << e4_quaternion - 5.63d << std::endl;

  std::cout << "4 - m4_quaternion = " << 4 - m4_quaternion << std::endl;
  std::cout << "6.23d - e1_quaternion = " << 6.23d - e4_quaternion << std::endl;
*/
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}
