#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"
#include <algorithm>

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // your code here
  T *arr = new T[mCap]();
  sort(pos.begin(), pos.end());
  int idx = 0;
  int realIndex = 0;
  int originalSize = mSize;

  for (int i = 0; i < originalSize; i++){
    if (i != pos[idx]){
      arr[realIndex] = mData[(mFront + i) % mCap];
      realIndex++;
    } else {
      idx++;
    }
  }
  delete [] mData;
  mData = arr;
  mSize -= pos.size();
  mFront = 0;
}

#endif
