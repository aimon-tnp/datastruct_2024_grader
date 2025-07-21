#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  //write your code here
  int ans = -1, s = mSize;
  while (s != 0){
    s /= 2;
    ans += 1;
  }
  return ans;
}

#endif

