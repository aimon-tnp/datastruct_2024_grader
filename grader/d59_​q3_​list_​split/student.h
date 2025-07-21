#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
  CP::list<T> result;
  if (pos == mSize){ // not adjusting, just return
    return result;
  }
  
  node *start = it.ptr;
  node *last = mHeader->prev;

  // re-link *this
  start->prev->next = mHeader;
  mHeader->prev = start->prev;

  // link 'result'
  start->prev = result.mHeader;
  result.mHeader->next = start;
  last->next = result.mHeader;
  result.mHeader->prev = last;

  // adjust mSize (both *this and result)
  result.mSize = mSize - pos;
  mSize = pos;

  return result;
}

#endif
