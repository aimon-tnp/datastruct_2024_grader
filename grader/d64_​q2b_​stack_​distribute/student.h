#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  //write your code here
  std::vector<std::vector<T>> r(k);
  int base = this->size() / k;
  int remainder = this->size() % k;

  for (int i = 0; i < k; i++){
    if (i < remainder){
      r[i] = std::vector<T>(base + 1);
    } else {
      r[i] = std::vector<T>(base);
    }
  }

  stack<T> temp = *this;
  for (int i = 0; i < k; i++){
    for (int j = 0; j < r[i].size(); j++){
      r[i][j] = temp.top();
      temp.pop();
    }
  }

  return r;
}

#endif
