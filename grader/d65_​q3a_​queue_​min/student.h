#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include <climits>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  //your code here
  T min ;
  int inside_pos = 0;
  for (int i = 0; i < pos.size(); i++){
    if (pos[i] >= mSize){
      continue;
    }

    if (inside_pos == 0){
      min = mData[(mFront + pos[i]) % mCap];
      inside_pos++;
    } else {
      if(comp(mData[(mFront + pos[i]) % mCap], min)){
        min = mData[(mFront + pos[i]) % mCap];
      }
    }
  }

  //should return something
  return min;
}

#endif
