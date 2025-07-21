#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  //write your code here
  T *newData = new T[mSize];
  int rotateRange = last - first;
  k %= rotateRange;


  // before 'first'
  for (int i = 0; i < (first - this->begin()); i++){
    newData[i] = mData[i];
  }

  // rotated data
  int trueIndex = first - this->begin();
  // for (int i = k; i <= rotateRange - 1; i++){
  //   newData[trueIndex] = mData[ (first - this->begin()) + i ];
  //   trueIndex++;
  // }

  // for (int i = 0; i < k; i++){
  //   newData[trueIndex] = mData[ (first - this->begin()) + i ];
  //   trueIndex++;
  // }

  for (int i = k; i <= k + rotateRange; i++){
    newData[trueIndex++] = mData[(first - this->begin()) + (i % rotateRange)];
  }

  // after 'last'
  for (int i = (last - this->begin()); i < mSize; i++){
    newData[i] = mData[i];
  }

  delete [] mData;
  mData = newData;
  mCap = mSize;
}

#endif
