#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last){
	// write your code here
	if (first < 0 ){
		first = 0;
	}
	if (last > mSize - 1){
		last = mSize - 1;
	}
	if (first >= last){
		return;
	}

	while (first < last){
		std::swap(mData[mSize - 1 - first], mData[mSize - 1 - last]);
		first++;
		last--;
	}
}

#endif
