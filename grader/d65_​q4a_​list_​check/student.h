#ifndef __STUDENT_H__
#define __STUDENT_H__


template <typename T>
bool CP::list<T>::check() {
  //your code here

  if (mSize == 0){
    return mHeader->next != mHeader && mHeader->prev != mHeader;
  }

  node *behind = mHeader;
  node *ahead = mHeader->next;
  // bool valid = true;
  for (int i = 1; i < mSize; i++){ // mSize - 1 loops
    if (behind == nullptr || ahead == nullptr){
      return false;
    }

    if (ahead->prev != behind){
      return false;
    }

    behind = behind->next;
    ahead = ahead->next;
  }

  if (behind == nullptr || ahead == nullptr){
    return false;
  }

  if (ahead->next != mHeader || mHeader->prev != ahead){
    return false;
  }

  return true;
}


#endif
