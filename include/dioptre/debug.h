#ifndef DIOPTRE_DEBUG_H_
#define DIOPTRE_DEBUG_H_

#include <vector>
#include <map>
#include <iostream>

#include "glm/mat4x4.hpp"

template <typename T>
inline void debug(const std::vector<T>& v) {
  std::cout << "[";
  for(auto& i : v) {
    std::cout << " " << i << " ";
  }
  std::cout << "]" << std::endl;
}

template <typename Key, typename T>
inline void debug(const std::map<Key, T> m) {
  std::cout << "[";

  for(auto it = m.begin(); it != m.end(); it++) {
    std::cout << " " << it->first << ":" << it->second;
  }

  std::cout << "]" << std::endl;
}

inline void debug(glm::mat4x4 m) {
  for (unsigned i = 0; i < 4; i++) {
    std::cout << "[" << m[0][i] << " " << m[1][i] << " " << m[2][i] << " " << m[3][i] << "]" << std::endl;
  }
}

template <typename T>
inline void debug(const T x) {
  std::cout << x << std::endl;
}

#endif
