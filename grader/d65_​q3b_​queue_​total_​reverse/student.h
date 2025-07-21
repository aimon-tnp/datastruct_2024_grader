#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T> // use aux as indicator whether the queue is reversed or not (0 = normal, 1 = reversed)
void CP::queue<T>::reverse() {
  // Your code here
  if (aux == 0){
    aux = 1;
  } else {
    aux = 0;
  }
}

template <typename T>
const T& CP::queue<T>::front() const {
  // You MAY need to edit this function
  if (aux == 1){
    return mData[(mFront + mSize - 1) % mCap];
  }
  return mData[mFront];
}

template <typename T>
const T& CP::queue<T>::back() const {
  // You MAY need to edit this function
  if (aux == 1){
    return mData[mFront];
  }
  return mData[(mFront + mSize - 1) % mCap];
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  // You MAY need to edit this function
  ensureCapacity(mSize + 1);
  if (aux == 1){
    mData[(mFront - 1 + mCap) % mCap] = element;
    mFront = (mFront - 1 + mCap) % mCap;
  } else {
    mData[(mFront + mSize) % mCap] = element;
  }
  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  // You MAY need to edit this function
  if (aux == 0){
    mFront = (mFront + 1) % mCap;
  }
  mSize--;
}

#endif