#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> time(n);
    vector<int> result(m);

    for (auto &e: time){
        cin >> e;
    }

    priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > pq; 

    for (int i = 0; i < n;i++){ // (time_available, chef_number)
        pq.push(make_pair(0, i));
    }

    for (int i = 0;i < m;i++){
        auto time_available = pq.top().first;
        auto chef_number = pq.top().second;
        pq.pop();

        result[i] = time_available;

        pq.push(make_pair(time_available + time[chef_number], chef_number));

    }

    for (auto &e : result){
        cout << e << endl;
    }

    return 0;
}