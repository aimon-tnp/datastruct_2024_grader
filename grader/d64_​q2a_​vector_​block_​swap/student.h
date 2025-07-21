#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  int A = a - this->begin();
  int B = b - this->begin();

  if (B > A){ // make sure that A > B
    int temp = A;
    A = B;
    B = temp;
  }

  if (A >= 0 && A < mSize && B >= 0 && B < mSize && m > 0
  && B+m-1 < A &&  A+m-1 < mSize){

    // T *newData = new T[mSize]();
    // int trueIndex = 0;

    // for (int i = 0; i < B; i++){ // before B
    //   newData[trueIndex++] = mData[i];
    // }
    // for (int i = A; i < A+m; i++){ // [A, A+m)
    //   newData[trueIndex++] = mData[i];
    // }
    // for (int i = B+m; i < A; i++){ // between A and B
    //   newData[trueIndex++] = mData[i];
    // }
    // for (int i = B; i < B+m; i++){ // [B, B+m)
    //   newData[trueIndex++] = mData[i];
    // }
    // for (int i = A+m; i < mSize; i++){ // after A
    //   newData[trueIndex++] = mData[i];
    // }
    // delete [] mData;
    // mData = newData;
    // mCap = mSize;

    for (int i = 0; i < m; i++){
      std::swap(*a,*b);
      ++a;
      ++b;
    }

    return true;
  } else {
    return false;
  }
}

#endif
