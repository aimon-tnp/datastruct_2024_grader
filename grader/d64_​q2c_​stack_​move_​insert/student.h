#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  //your code here
  CP::stack<T> temp;
  if (k > this->size()){
    k = this->size();
  }

  if (m > s2.size()){
    m = s2.size();
  }

  for (int i = 0; i < k; i++){
    temp.push(this->top());
    this->pop();
  }

  for (int i = 0; i < m; i++){
    temp.push(s2.top());
    s2.pop();
  }

  while (!temp.empty()){
    this->push(temp.top());
    temp.pop();
  }
}

#endif
