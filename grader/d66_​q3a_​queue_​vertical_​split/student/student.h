#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::v_split(std::vector<std::queue<T>> &output, size_t k) const
{
  // your code here
  output.resize(k);
  int base = mSize / k;
  int remainder = mSize % k;
  int idx = 0;
  for (int i = 0; i < k; i++){
    if (i < remainder){
      for (int j = 0; j < base + 1; j++){
        output[i].push(mData[(mFront + idx) % mCap]);
        idx++;
      }

    } else {
      for (int j = 0; j < base; j++){
        output[i].push(mData[(mFront + idx) % mCap]);
        idx++;
      }

    }
  }
}

#endif
