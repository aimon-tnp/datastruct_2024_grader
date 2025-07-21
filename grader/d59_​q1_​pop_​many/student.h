#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  //write your code here
  if (K > this->size()){
    K = this->size();
  }

  for (int i = 0; i < K; i++){
    this->pop();
  }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  //write your code here
  //
  //don't forget to return an std::stack
  if (K > this->size()){
    K = this->size();
  }

  std::vector<int> temp(K);

  for (int i = 0; i < K; i++){
    temp[i] = this->top();
    this->pop();
  }

  std::stack<T> t;
  for (int i = temp.size() - 1; i >= 0; i--){
    t.push(temp[i]);
  }

  return t;
}

#endif
