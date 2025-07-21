#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  //write your code here
  if (a == b){
    return;
  }
  for (auto it = a; it != b;){
    if(*it == value){
      iterator temp(it.ptr->next);
      it.ptr->prev->next = it.ptr->next;
      it.ptr->next->prev = it.ptr->prev;
      delete it.ptr;
      mSize--;
      it = temp;

      // output.insert(output.begin(), value);

      // arrangement: mHeader -> n -> output_begin (oldbegin)
      auto output_begin = output.mHeader->next; // first element
      node *n = new node(value, output.mHeader, output_begin);
      output.mHeader->next = n; // link next of mHeader to n
      output_begin->prev = n; // link prev of old_begin to n
      output.mSize++;
      
    } else {
      it++;
    }

  }

}

#endif
