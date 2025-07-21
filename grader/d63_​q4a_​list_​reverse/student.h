#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  //write your code here
  if (a == b || mSize == 0){
    return a;
  }

  iterator ret = a;
  iterator start = a;
  iterator stop = b.ptr->prev;
  int count = 0;
  while (start != b){
    count++;
    start++;
  }

  // start = a;
  
  for (int i = 0; i < count / 2; i++){
    std::swap(*a, *stop);
    a++;
    stop--;
  }

  return ret;

}

#endif
