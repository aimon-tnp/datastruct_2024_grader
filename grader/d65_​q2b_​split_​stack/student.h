#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  //your code here
  //should return something
  std::vector<std::vector<T>> r(k);
  for (int i = 0; i < mSize; i++){
    r[i%k].insert(r[i%k].begin(), mData[mSize - 1 - i]);
  }
  return r;
}

#endif

