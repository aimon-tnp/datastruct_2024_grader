// Your code here
int height(node *n){ // find height of specific node
    if (n == NULL){
        return -1;
    }
    return 1 + std::max(height(n->left), height(n->right));
}

int getImb(node *n){
    int lefth = height(n->left);
    int righth = height(n->right);
    return std::abs(lefth - righth);
}

void findMostImb(node *n, node* &mostImb){ // mostImb มีการแก้ไขค่าเรื่อยๆ โดยเช็คจาก n (ควรจะเป็น mRoot)
    if (n == NULL){
        return;
    }

    if (getImb(n) > getImb(mostImb) || (getImb(n) == getImb(mostImb) && n->data.first < mostImb->data.first)){
        mostImb = n;
    }

    findMostImb(n->left, mostImb);
    findMostImb(n->right, mostImb);
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    node *n = mRoot;
    findMostImb(mRoot, n);
    return n->data.first;
}
