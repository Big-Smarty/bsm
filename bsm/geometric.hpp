#pragma once

#include <cmath>
#include <math.h>

namespace bsm {
template <typename T, unsigned L> struct Vec {
  Vec() = default;
  template <typename... Ts>
  Vec(Ts... params) noexcept requires(sizeof...(params) == L)
      : m_vec{params...} {}

  T &operator[](unsigned i) { return m_vec[i]; }

  unsigned length() { return L; }
  float magnitude();

private:
  T m_vec[L]{};
};
template <typename T, unsigned C, unsigned R> struct Mat {
  Mat() = default;
  template <typename... Ts>
  Mat(Ts... params) noexcept requires(sizeof...(params) == R)
      : m_mat{params...} {}

  T &operator[](unsigned i) { return m_mat[i]; }

  template <unsigned N>
  Mat<T, N, R> &operator*(const Mat<T, N, C> other) noexcept {
    Mat<T, N, R> out;
    unsigned c_index = 0;
    unsigned r_index = 0;
    T temp_sum{};
    for (unsigned r = 0; r < R; r++) {
      for (unsigned n = 0; n < N; n++) {
        for (unsigned c = 0; c < C; c++) {
          temp_sum = *this[r][c] * other[n][c];
        }
        out[c_index][r_index] = temp_sum;
        c_index++;
      }
      r_index++;
    }
  }

  Vec<unsigned, 2> dimensions() { return Vec<unsigned, 2>(C, R); }

private:
  Vec<Vec<T, R>, C> m_mat{};
};
} // namespace bsm

#include "geometric.inl"
