#pragma once
#include <cmath>
#include <complex>
#include <array>
#include <iostream>


namespace algebra {

  template <typename T>
  class quaternion;

  template <typename T>
  std::ostream& operator<<(std::ostream& os, const quaternion<T>& q);

  template <typename T>
  quaternion<T> operator+(const quaternion<T>& q1, const quaternion<T>& q2);

  template <typename T>
  quaternion<T> operator-(const quaternion<T>& q1, const quaternion<T>& q2);

  template <typename T>
  class quaternion {

  private:
      T a, b, c, d;

  public:
      quaternion();

      quaternion(T u, T v, T w, T x);

      quaternion(T u, T v, T w) : quaternion(u, v, w, static_cast<T>(0)) {};

      quaternion(T u, T v) : quaternion(u, v, static_cast<T>(0), static_cast<T>(0)) {};

      quaternion(T u) : quaternion(u, static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)) {};

      T real();

      void real(T const & v);

      std::array<T, 3> imag();

      void imag(std::array<T, 3> const & v);

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

      friend std::ostream& operator<< <T>(std::ostream& os, const quaternion<T>& q);

      friend quaternion<T> operator+ <T>(const quaternion<T>& q1, const quaternion<T>& q2);

      friend quaternion<T> operator- <T>(const quaternion<T>& q1, const quaternion<T>& q2);

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
  std::ostream& operator<<(std::ostream& os, const quaternion<T>& q) {
      os << "(" << q.a << "," << q.b << "," << q.c << "," << q.d << ")";
      return os;
  }

  template <typename T>
  quaternion<T> operator+(const quaternion<T>& q1, const quaternion<T>& q2) {
      quaternion<T> q3;
      q3.a = q1.a + q2.a;
      q3.b = q1.b + q2.b;
      q3.c = q1.c + q2.c;
      q3.d = q1.d + q2.d;
      return q3;
  }

  template <typename T>
  quaternion<T> operator-(const quaternion<T>& q1, const quaternion<T>& q2) {
      quaternion<T> q3;
      q3.a = q1.a - q2.a;
      q3.b = q1.b - q2.b;
      q3.c = q1.c - q2.c;
      q3.d = q1.d - q2.d;
      return q3;
  }

  template <typename T>
  T algebra::quaternion<T>::real() {
    return a;
  }

  template <typename T>
  void algebra::quaternion<T>::real(T const & v) {
    a = v;
  }

  template <typename T>
  std::array<T, 3> algebra::quaternion<T>::imag() {
    return std::array<T, 3> {b, c, d};
  }

  template <typename T>
  void algebra::quaternion<T>::imag(std::array<T, 3> const & v) {
    b = v[0];
    c = v[1];
    d = v[2];
  }

}
