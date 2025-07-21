#include <iostream>
#include <vector>
#include <map>
using namespace std;
void insert_into_sv(map<int, int> &v, int pos, int value)
{
    // your code here
    auto it = v.lower_bound(pos);
    map<int, int> temp;
    while(it != v.end()){
        temp[ (*it).first + 1 ] = (*it).second; // shifted element
        it++;
    }
    
    // cout << endl;
    // for (auto &e : temp){
    //     cout << e.first << " -> " << e.second << endl;
    // }

    for (auto i = temp.rbegin();i!=temp.rend();i++){ // delete unshifted element and add shifted ones
        auto e = (*i);
        v.erase(e.first - 1);
        v[e.first] = e.second;
    }

    v[pos] = value; // entirely new element

    cout << endl;
    for (auto &e : v){
        cout << e.first << " -> " << e.second << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    map<int, int> v;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        insert_into_sv(v, a, b);
    }

    cout << v.size() << "\n";
    for (auto &x : v)
    {
        cout << x.first << ": " << x.second << "\n";
    }
}