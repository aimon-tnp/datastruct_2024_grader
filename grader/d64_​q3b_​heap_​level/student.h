#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"
#include <math.h>
#include <algorithm>

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> r;
  int start = (1 << k) - 1;
  int stop = (1 << (k+1)) - 1;
  if (stop > mSize){
    stop = mSize;
  }

  for(int i = start; i < stop; i++){
    r.push_back(mData[i]);
  }

  std::sort(r.rbegin(), r.rend(), mLess);

  return r;
}

#endif

