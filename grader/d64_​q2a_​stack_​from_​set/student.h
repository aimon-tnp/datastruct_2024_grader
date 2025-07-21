#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  //write your code ONLY here
  mData = new T[std::distance(first, last)]();
  mSize = std::distance(first, last);
  mCap = mSize;

  int n = 0;
  for (auto it = first; it != last; it++){
    mData[mSize - 1 - n] = *it;
    n++;
  }
}

#endif
