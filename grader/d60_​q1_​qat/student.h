#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
T CP::queue<T>::operator[](int idx) {
  //write something here
  //
  // you need to return something
  // return 

  T ans;
  if (idx >= 0){ // 0, positive case
    ans = mData[(mFront + idx) % mCap];
  } else { // negative case
    ans = mData[(mFront + mSize + idx) % mCap]; // mData[mFront + mSize - 1] == back() == (idx = -1)
  }
  return ans;
}

#endif
