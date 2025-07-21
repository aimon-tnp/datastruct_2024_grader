#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <assert.h>

template <typename T,typename Comp>
void CP::priority_queue<T,Comp>::change_value(size_t pos,const T& value) {
  //write your code here
  T temp = mData[pos];
  mData[pos] = value;

  if (mLess(value, temp)){
    fixDown(pos);
  } else if (!mLess(value, temp)){
    fixUp(pos);
  }
}

#endif
