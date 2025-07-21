#ifndef _CP_STUDENT_QUEUE_INCLUDED_
#define _CP_STUDENT_QUEUE_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once
#include <vector>
#include <queue>
#include "queue.h"

template <typename T>
std::vector< CP::queue<T> > CP::queue<T>::split_queue(int k) {
    std::vector<CP::queue<T> > qs(k);
    // code here
    int start = 0;
    while(!this->empty()){
        qs[start % k].push(this->front());
        this->pop();
        start++;
    }
    return qs;
}

#endif

