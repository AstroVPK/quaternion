#pragma once
#include <cmath>
#include <complex>
#include <array>
#include <type_traits>
#include <iostream>


namespace algebra {

  template <typename T>
  class quaternion {

  public:
      using value_type = T;

      T a, b, c, d;

      quaternion();

      quaternion(T u, T v, T w, T x);

      quaternion(T u, T v, T w) : quaternion(u, v, w, static_cast<T>(0)) {};

      quaternion(T u, T v) : quaternion(u, v, static_cast<T>(0), static_cast<T>(0)) {};

      quaternion(T u) : quaternion(u, static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)) {};

      template <typename U, typename V, typename W, typename X>
      quaternion(U u, V v, W w, X x);

      template <typename U, typename V, typename W>
      quaternion(U u, V v, W w) : quaternion(u, v, w, static_cast<T>(0)) {};

      template <typename U, typename V>
      quaternion(U u, V v) : quaternion(u, v, static_cast<T>(0), static_cast<T>(0)) {};

      template <typename U>
      quaternion(U u) : quaternion(u, static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)) {};

      template <typename U>
      quaternion(std::complex<U> z);

      T real() const;

      void real(T const & v);

      std::array<T, 3> imag() const;

      void imag(std::array<T, 3> const & v);

      const quaternion<T> & operator+=(quaternion<T> const & q);

      const quaternion<T> & operator-=(quaternion<T> const & q);

  };

  template <typename T>
  algebra::quaternion<T>::quaternion() {
    a = static_cast<T>(0);
    b = static_cast<T>(0);
    c = static_cast<T>(0);
    d = static_cast<T>(0);
  }

  template <typename T>
  algebra::quaternion<T>::quaternion(T u, T v, T w, T x) {
    a = u;
    b = v;
    c = w;
    d = x;
  }

  template <typename T>
  template <typename U, typename V, typename W, typename X>
  algebra::quaternion<T>::quaternion(U u, V v, W w, X x) {
    a = static_cast<T>(u);
    b = static_cast<T>(v);
    c = static_cast<T>(w);
    d = static_cast<T>(x);
  }

  template <typename T>
  template <typename U>
  algebra::quaternion<T>::quaternion(std::complex<U> z) {
    a = static_cast<T>(z.real());
    b = static_cast<T>(z.imag());
    c = static_cast<T>(0);
    d = static_cast<T>(0);
  }

  template <typename T>
  T algebra::quaternion<T>::real() const {
    return a;
  }

  template <typename T>
  void algebra::quaternion<T>::real(T const & v) {
    a = v;
  }

  template <typename T>
  std::array<T, 3> algebra::quaternion<T>::imag() const {
    return std::array<T, 3> {b, c, d};
  }

  template <typename T>
  void algebra::quaternion<T>::imag(std::array<T, 3> const & v) {
    b = v[0];
    c = v[1];
    d = v[2];
  }

  template<typename T>
  const quaternion<T>& algebra::quaternion<T>::operator+=(quaternion<T> const & q) {
    this->a += q.a;
    this->b += q.b;
    this->c += q.c;
    this->d += q.d;
    return *this;
  }

  template<typename T>
  const quaternion<T>& algebra::quaternion<T>::operator-=(quaternion<T> const & q) {
    this->a -= q.a;
    this->b -= q.b;
    this->c -= q.c;
    this->d -= q.d;
    return *this;
  }

  template <typename T>
  std::ostream& operator<<(std::ostream& os, const quaternion<T>& q) {
    os << "(" << q.a << "," << q.b << "," << q.c << "," << q.d << ")";
    return os;
  }

  template <typename T1, typename T2>
  const quaternion<typename std::common_type<T1, T2>::type> operator+(const quaternion<T1>& q1, const quaternion<T2>& q2) {
    return quaternion<typename std::common_type<T1, T2>::type>(q1.a + q2.a, q1.b + q2.b, q1.c + q2.c, q1.d + q2.d);
  }

  template <typename T1, typename T2>
  const quaternion<typename std::common_type<T1, T2>::type> operator+(const quaternion<T1>& q1, const T2& q2) {
    return quaternion<typename std::common_type<T1, T2>::type>(static_cast<typename std::common_type<T1, T2>::type>(q1.a) + static_cast<typename std::common_type<T1, T2>::type>(q2), q1.b, q1.c, q1.d);
  }

  template <typename T1, typename T2>
  const quaternion<typename std::common_type<T1, T2>::type> operator+(const T1& q1, const quaternion<T2>& q2) {
    return quaternion<typename std::common_type<T1, T2>::type>(static_cast<typename std::common_type<T1, T2>::type>(q1) + static_cast<typename std::common_type<T1, T2>::type>(q2.a), q2.b, q2.c, q2.d);
  }

  template <typename T1, typename T2>
  const quaternion<typename std::common_type<T1, T2>::type> operator-(const quaternion<T1>& q1, const quaternion<T2>& q2) {
    return quaternion<typename std::common_type<T1, T2>::type>(q1.a - q2.a, q1.b - q2.b, q1.c - q2.c, q1.d - q2.d);
  }

  template <typename T1, typename T2>
  const quaternion<typename std::common_type<T1, T2>::type> operator-(const quaternion<T1>& q1, const T2& q2) {
    return quaternion<typename std::common_type<T1, T2>::type>(static_cast<typename std::common_type<T1, T2>::type>(q1.a) - static_cast<typename std::common_type<T1, T2>::type>(q2), q1.b, q1.c, q1.d);
  }

  template <typename T1, typename T2>
  const quaternion<typename std::common_type<T1, T2>::type> operator-(const T1& q1, const quaternion<T2>& q2) {
    return quaternion<typename std::common_type<T1, T2>::type>(static_cast<typename std::common_type<T1, T2>::type>(q1) - static_cast<typename std::common_type<T1, T2>::type>(q2.a), q2.b, q2.c, q2.d);
  }

}
