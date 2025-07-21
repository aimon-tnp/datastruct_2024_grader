#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    if (!m){
        cout << 0;
        return 0;
    }


    // int left = m * 2 + 1, right = left + 1;
    vector<int> marking(n,0);
    queue<int> q;
    q.push(m);

    while (!q.empty()){
        marking[q.front()] -= 1;
        if (q.front() * 2 + 1 < n){
            q.push(q.front() * 2 + 1);
        }
        if (q.front() * 2 + 2 < n){
            q.push(q.front() * 2 + 2);
        }
        q.pop();
    }


    cout << count(marking.begin(), marking.end(), 0) << endl;
    // int marking_idx = 0;
    for (int i = 0; i < marking.size(); i++){
        if (marking[i] == 0){
            cout << i << " ";
        } else {
            continue;
        }
    }
    return 0;
}