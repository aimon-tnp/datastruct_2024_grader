#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) { // {1,2,3,4,5,6} ->(3) {1,2,3,5,6,4}
  //write your code here
  T temp = mData[(mFront + pos) % mCap];
  int count = mSize - pos - 1;
  int idx = (mFront + pos) % mCap;
  while(count--){
    mData[idx] = mData[(idx + 1) % mCap];
    idx = (idx + 1) % mCap;
  }

  mData[(mFront + mSize - 1) % mCap] = temp;
}

#endif
