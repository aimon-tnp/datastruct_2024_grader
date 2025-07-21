#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
  // Write code here
  std::vector<int> mark(mSize,0);
  for (auto e : ranges){ // [0,0,0,0,0,0] -> [0,1,1,0,-1,0,-1]
    int a = e.first - this->begin();
    int b = e.second - this->begin();
    mark[a] += 1;
    if (b < mSize){
      mark[b] -= 1;
    }
  }


  int trueIndex = 0, rIndex = 0, indi = 0;
  while (rIndex < mSize){
    indi += mark[rIndex];
    if (indi == 0){
      mData[trueIndex] = mData[rIndex];
      trueIndex += 1;
    }
    rIndex += 1;
  }
  mSize = trueIndex;
  mCap = mSize;

}

#endif

