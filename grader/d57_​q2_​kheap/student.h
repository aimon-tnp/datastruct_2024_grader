#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>


template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) { // parent (idx - 1) / k
    T temp = mData[idx];
    while (idx > 0){
        int parent = (idx - 1) / 4;
        if (!mLess(mData[parent], temp)){ // temp has higher priority than parent -> not satisfied
            break;
        } else {
            mData[idx] = mData[parent];
            idx = parent;
        }
    }
    mData[idx] = temp;
}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
    T temp = mData[idx];
    size_t c, compared;
    while ((c = (idx * 4) + 1) < mSize){
        compared = c;
        if (c + 1 < mSize && mLess(mData[compared], mData[c+1])){ // find highest priority among children
            compared = c + 1;
        }
        if (c + 2 < mSize && mLess(mData[compared], mData[c+2])){
            compared = c + 2;
        }
        if (c + 3 < mSize && mLess(mData[compared], mData[c+3])){
            compared = c + 3;
        }

        if (mLess(mData[compared], temp)){ // if child < temp(parent) -> correct
            break;
        } else {
            mData[idx] = mData[compared];
            idx = compared;
        }
    }
    mData[idx] = temp;
}

#endif

