#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here

  sort(data.begin(), data.end());
  T *newData = new T[mSize + data.size()];
  size_t pos = 0;
  size_t trueIndex = 0;
  for (int i = 0; i < mSize; i++){
    if (data[pos].first == i){
      newData[trueIndex] = data[pos].second;
      pos++;
      trueIndex++;
    }

    newData[trueIndex] = mData[i];
    trueIndex++;

  }

  if (pos < data.size()){
    newData[trueIndex] = (*(data.end() - 1)).second;
  }

  delete [] mData;
  mData = newData;
  mSize += data.size();
  mCap = mSize;


}

#endif
