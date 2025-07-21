void shift(int k) {
	// TODO: Add your code here
	int ms = mSize;
	k = k % ms;
	if (k < 0){
		k = k + ms;
	}
	node *p = mHeader->next;

	for (int i = 0; i < k; i++){
		p = p->next;
	}

	// link first element with last element
	mHeader->next->prev = mHeader->prev;
	mHeader->prev->next = mHeader->next;

	// link mHeader to 2 elements
	mHeader->next = p;
	mHeader->prev = p->prev;
	
	// link A,B to mHeader
	p->prev->next = mHeader;
	p->prev = mHeader;

}
