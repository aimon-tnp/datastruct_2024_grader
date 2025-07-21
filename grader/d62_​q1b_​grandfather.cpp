#include <iostream>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;

    map<long long, long long> relations; // kid - parent

    long long kid, parent; // temporary input
    for (int i = 0;i < n;i++){
        cin >> parent >> kid;
        relations[kid] = parent;
    }

    long long id1, id2; // temporary input
    for (int i = 0;i < m;i++){
        cin >> id1 >> id2;
        if (id1 == id2 || relations[id1] == 0 || relations[id2] == 0){ // id1 == id2, not exist (depth:1)
            cout << "NO" << endl;
        } else if (relations[relations[id1]] == 0 || relations[relations[id2]] == 0){ // not exist, (depth:2)
            cout << "NO" << endl;
        } else {
            if (relations[relations[id1]] == relations[relations[id2]]){ // both grandparent exist, check if equal
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}