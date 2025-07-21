#include <iostream>

using namespace std;

int main(){
    int n,start = 1;
    cin >> n;
    while(start < n){
        start *= 2;
    }
    cout << start - n;
    return 0;
}