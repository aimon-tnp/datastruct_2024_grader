#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void member_multiply(vector<int> &v, vector<pair<vector<int>::iterator, int> > &multiply)
{
    // write your code here
    vector<int> new_v = v;
    sort(multiply.begin(), multiply.end(), [](const auto &a, const auto &b)
         { return a.first > b.first; });

    for (auto &element : multiply)
    {
        auto it = element.first;
        int count = element.second;
        int value = *it;
        int index = distance(v.begin(), it);
        
        new_v.insert(new_v.begin() + index, count, value);
    }
    v = new_v;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<vector<int>::iterator, int> > multiply(m);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        multiply[i].first = v.begin() + a;
        multiply[i].second = b;
    }
    member_multiply(v, multiply);
    cout << "======= result ========" << endl;
    cout << v.size() << endl;
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}