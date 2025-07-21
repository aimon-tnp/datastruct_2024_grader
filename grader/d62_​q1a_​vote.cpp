#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    map<string, int> m;
    for (int i=0;i<N;i++){
        string temp;
        cin >> temp;
        m[temp]++;
    }

    vector<int> scores;
    for (auto &element : m){
        scores.push_back(element.second);
    }
    sort(scores.begin(), scores.end(), greater<int>());

    if (scores.size() < K){
        cout << scores.back();
    } else {
        cout << scores[K - 1];
    }

    return 0;
}