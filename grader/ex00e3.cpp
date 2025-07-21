#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;

    map<int, int> m; // number : 1
    for (int i=1;i<=n;i++){
        m[i] = 1;
    }

    bool permutation = true;
    for (int i=0;i<n;i++){
        int temp;
        cin >> temp;

        if (m.find(temp) == m.end()){
            permutation = false;
        } else {
            m[temp] -= 1;
        }
    }

    for (auto &element : m){
        if (element.second != 0){
            permutation = false;
        }
    }

    if (permutation){
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}