#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here

  if (pos.size() == 0){
    return ;
  } else {
    for (int i = pos.size() - 1; i >= 0; i--){
      this->erase(this->begin() + pos[i]);
    }
  }

}

#endif
