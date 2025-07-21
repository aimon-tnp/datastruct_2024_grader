#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    //write your code here
    int this_reserved = this->mCap - this->mSize;
    int other_reserved = other.mCap - other.mSize;

    if (this_reserved < other_reserved){
        return -1;
    } else if (this_reserved == other_reserved){
        return 0;
    } else {
        return 1;
    }
}

#endif
