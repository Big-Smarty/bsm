#pragma once

#include "geometric.hpp"
namespace bsm {
template <typename T, unsigned L>
Vec<T, L> operator*(const Vec<T, L> &lhs, const Vec<T, L> &rhs) {
  Vec<T, L> out;
  for (unsigned i = 0; i < lhs.length(); i++) {
    out[i] = lhs[i] * rhs[i];
  }
  return out;
}
template <typename T, unsigned L> float Vec<T, L>::magnitude() {
  float squared_sum = 0.0f;
  for (int i = 0; i < L; i++) {
    squared_sum += m_vec[i];
  }
  return sqrtf(squared_sum);
}
} // namespace bsm
