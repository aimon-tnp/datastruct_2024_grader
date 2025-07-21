#ifndef __STUDENT_H
#define __STUDENT_H

#include "priority_queue.h"

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::check() {
  // Your code here
  // Return something
  for (int i = 0; i < mSize; i++){
    // left node
    if (i*2+1 < mSize){
      if (!mLess(mData[i*2+1], mData[i])){
        return false;
      }
    }

    // right node
    if (i*2+2 < mSize){
      if (!mLess(mData[i*2+2], mData[i])){
        return false;
      }
    }
  }
  return true;
}

#endif