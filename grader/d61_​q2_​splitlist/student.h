void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here

    int times;
    if (mSize % 2 == 0){
        times = mSize / 2;
    } else {
        times = (mSize / 2) + 1;
    }

    node *lastofl1 = mHeader->next; // ชี้ไปก่อนเลยรอบนึงแล้ว ทำ for loop เริ่มที่ 1 แทน
    for (int i = 1; i < times; i++){
        lastofl1 = lastofl1->next;
    }

    node *beginofl2 = lastofl1->next;

    // linking each sublist
    // l1 {oldlist1, begin to lastofl1, mHeader}
    list1.mHeader->prev->next = mHeader->next;
    mHeader->next->prev = list1.mHeader->prev;

    lastofl1->next = list1.mHeader;
    list1.mHeader->prev = lastofl1;

    // l2 {oldlist1, beginofl2 to back, mHeader}
    list2.mHeader->prev->next = beginofl2;
    beginofl2->prev = list2.mHeader->prev;

    mHeader->prev->next = list2.mHeader;
    list2.mHeader->prev = mHeader->prev;

    // update l1 and l2 mSize
    list1.mSize += times;
    list2.mSize += (mSize - times);

    // update *this properties
    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    mSize = 0;

}
