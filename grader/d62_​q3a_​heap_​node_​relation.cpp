#include <iostream>

using namespace std;

int main(){
    int mSize, x, a, b, lowernode, uppernode;
    cin >> mSize >> x;
    while(x--){
        cin >> a >> b;
        if (a == b){ // a == b
            cout << "a and b are the same node" << endl;
            continue;
        }
        if (!a){
            cout << "a is an ancestor of b" << endl;
            continue;
        }
        if (!b){
            cout << "b is an ancestor of a" << endl;
            continue;
        }

        if (a > b){
            lowernode = a;
            uppernode = b;
        } else {
            lowernode = b;
            uppernode = a;
        }
        while (lowernode > 0){
            lowernode = (lowernode - 1) / 2;
            if (lowernode == uppernode){
                break;
            }
        }
        if (lowernode == 0){
            cout << "a and b are not related" << endl;
        } else {
            if (a > b){
                cout << "b is an ancestor of a" << endl;
            } else {
                cout << "a is an ancestor of b" << endl;
            }
        } 
    }

    return 0;
}