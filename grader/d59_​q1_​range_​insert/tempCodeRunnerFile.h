#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here

  int breakpoint = position - this->begin();
  int expandedRange = last - first;
  T *newData = new T[mSize + expandedRange];
  for (int i = 0; i < breakpoint; i++){
    newData[i] = mData[i];
  }

  int trueIndex = breakpoint;
  for (auto it = first; it != last; it++){
    newData[trueIndex] = *it;
    trueIndex++;
  }

  for (int i = breakpoint; i < mSize + expandedRange; i++){
    newData[trueIndex] = mData[i];
    trueIndex++;
  }

  delete [] mData;
  mCap = mSize;
  mData = newData;
}

#endif
