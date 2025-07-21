#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "stack.h"

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
  // Write code here
  if (mSize != 0){
    output.resize(k);
    int base = mSize / k;
    int remainder = mSize % k;
    int idx = 0;
    for (int i = k - 1; i >= 0; i--){
      int times = base;
      if (i < remainder){
        times += 1;
      }

      for (int j = 0; j < times; j++){
        output[i].push(mData[idx]);
        idx++;
      }

    }
  }
}

#endif
