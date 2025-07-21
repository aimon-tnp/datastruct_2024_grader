#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator==(const vector<T> &other) const {
  //write your code only in this function
  if (mSize != other.mSize){
    return false; 
  } else {
    for (size_t pos = 0; pos <= mSize - 1; pos++){
      if (mData[pos] != other.mData[pos]){
        return false;
      }
    }
    return true;
  }

}

#endif
