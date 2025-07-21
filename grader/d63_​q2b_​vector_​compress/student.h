#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    //write your code here
    T *newData = new T[mSize]();
    for (int i = 0; i <= mSize - 1; i++){
        newData[i] = mData[i];
    }
    delete [] mData;
    mCap = mSize;
    mData = newData;
}

#endif
