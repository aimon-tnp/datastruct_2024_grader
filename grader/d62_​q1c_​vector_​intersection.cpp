#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    set<int> A,B;

    int temp_input;
    for (int i = 0;i < n;i++){
        cin >> temp_input;
        A.insert(temp_input);
    }
    for (int i = 0;i < m;i++){
        cin >> temp_input;
        B.insert(temp_input);
    }

    vector<int> intersect;

    for (auto &n : A){
        if(B.find(n) != B.end()){
            intersect.push_back(n);
        }
    }

    sort(intersect.begin(), intersect.end());
    for (auto &element : intersect){
        cout << element << " ";
    }
    
    return 0;
}