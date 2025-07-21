#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const { // format [return mLess(a,b) ? b : a] will return higher priority
  //write your code here
  //can include anything
  if (k == 1){
    return mData[0];
  } else if (k == 2){
    return mLess(mData[1], mData[2]) ? mData[2] : mData[1];
  } else if (k == 3){
    if (mLess(mData[1], mData[2])){ // true -> m1 < m2 (check m1,m5,m6)
      T high_priority = mLess(mData[5], mData[6]) ? mData[6] : mData[5];
      return mLess(mData[1], high_priority) ? high_priority : mData[1];
    } else { // false -> m1 > m2 (check m2,m3,m4)
      T high_priority = mLess(mData[3], mData[4]) ? mData[4] : mData[3];
      return mLess(mData[2], high_priority) ? high_priority : mData[2];
    }
  }
}

#endif
