#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    long long mCap = 1, mSize = 0;
    for (int i = 0; i < n; i++){
        int a, k;
        cin >> a >> k;
        if (a == 0){
            while(mSize + k > mCap){
                mCap *= 2;
            }     
            mSize += k;
        } else {
            mSize -= k;
        }
    }
    cout << mCap - mSize;

    return 0;
}