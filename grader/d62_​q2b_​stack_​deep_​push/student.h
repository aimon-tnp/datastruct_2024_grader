#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
  stack<T> s;
  for (size_t i = 0; i < pos; i++){
    s.push(this->top());
    this->pop();
  }

  this->push(value);
  for (size_t i = 0; i < pos; i++){
    this->push(s.top());
    s.pop();
  }

}

#endif
