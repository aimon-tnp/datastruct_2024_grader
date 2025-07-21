#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n, a;
    cin >> n >> a;

    queue<int> q;
    vector<int> v;
    q.push(a);

    while (!q.empty()){
        v.push_back(q.front());
        if (q.front() * 2 + 1 < n){
            q.push(q.front() * 2 + 1);
        }
        if (q.front() * 2 + 2 < n){
            q.push(q.front() * 2 + 2);
        }
        q.pop();
    }

    cout << v.size() << endl;
    for (auto &e : v)
    {
        cout << e << " ";
    }

    return 0;
}