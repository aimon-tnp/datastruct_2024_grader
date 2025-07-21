#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "list.h"

template <typename T>
void CP::list<T>::block_swap(iterator a1, iterator a2, iterator b1, iterator b2) {
	// write your code here
	if (a1 == a2 || b1 == b2){ // no swapping required
		return;
	}
	node *c1 = a1.ptr->prev;
	node *c2 = a2.ptr->prev;
	node *d1 = b1.ptr->prev;
	node *d2 = b2.ptr->prev;

	// c1&b1, a2&d2, d1&a1, c2&b2

	c1->next = b1.ptr;
	b1.ptr->prev = c1;

	d2->next = a2.ptr;
	a2.ptr->prev = d2;

	c2->next = b2.ptr;
	b2.ptr->prev = c2;

	d1->next = a1.ptr;
	a1.ptr->prev = d1;

}

#endif
