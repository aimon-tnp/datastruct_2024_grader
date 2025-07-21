#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include <set>
using namespace std;

template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  set<T> s;
  size_t pos = 0;
  for (int i = 0; i < mSize; i++){
    if (s.find(mData[i]) == s.end()){ // not found
      s.insert(mData[i]);
      mData[pos] = mData[i];
      pos += 1;
    }
  }
  mSize = pos;
}

#endif
