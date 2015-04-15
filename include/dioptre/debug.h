#ifndef DIOPTRE_DEBUG_H_
#define DIOPTRE_DEBUG_H_

#include <vector>
#include <map>
#include <iostream>

template <typename T>
void debug(const std::vector<T>& v) {
  std::cout << "[";
  for(auto& i : v) {
    std::cout << " " << i << " ";
  }
  std::cout << "]" << std::endl;
}

template <typename Key, typename T>
void debug(const std::map<Key, T> m) {
  std::cout << "[";

  for(auto it = m.begin(); it != m.end(); it++) {
    std::cout << " " << it->first << ":" << it->second;
  }

  std::cout << "]" << std::endl;
}

template <typename T>
void debug(const T x) {
  std::cout << x << std::endl;
}

#endif
