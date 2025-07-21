#ifndef __STUDENT_H_
#define __STUDENT_H_

//can include anything

#include <algorithm>
#include <vector>

template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos,CompareT  comp) {
  // Write code here
  // you can compare two data A and B of type T by calling comp(A,B)
  // which return true when A is less than B
  sort(pos.begin(), pos.end());
  std::vector<T> sorted_data;
  for (auto &e : pos)
  {
    sorted_data.push_back(*e);
  }
  sort(sorted_data.begin(), sorted_data.end(), comp);

  int idx = 0;
  for (auto &e : pos)
  {
    *e = sorted_data[idx];
    idx++;
  }
  

}

#endif
