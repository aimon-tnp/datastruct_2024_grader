#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  //write your code here
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ensureCapacity(mSize * 2);

  auto it_ori = this->end() - 1;
  auto it_mirrored = this->end();
  for (size_t i = 0; i < mSize; i++){
    *it_mirrored = *it_ori;
    --it_ori;
    ++it_mirrored;
  }

  mSize *= 2;
}

#endif
