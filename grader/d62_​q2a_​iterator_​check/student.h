#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::valid_iterator(CP::vector<T>::iterator it) const {
  //write your code here
  size_t index = it - &mData[0]; // &mData[0] = begin()
  if (index >= 0 && index < mSize){
    return true;
  } else {
    return false;
  }

}

#endif
