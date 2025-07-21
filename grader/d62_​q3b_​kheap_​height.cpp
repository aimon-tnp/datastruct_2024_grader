#include <iostream>

using namespace std;

int main(){
    long long mSize, k; // mSize, rate mgiht be enormous, so switching from 'int' to 'long long' is better.
    cin >> mSize >> k;
    long long height = -1, sum = 0, nodes = 1;
    while (sum < mSize){
        sum += nodes;
        nodes *= k;
        height++;
    }

    cout << height;

    return 0;
}