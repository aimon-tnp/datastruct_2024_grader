#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator it, int k)
{
    // write some code here
    
    auto start = (it - k < v.begin() ? v.begin() : it - k); // if less then begin(), return begin()
    auto end = (it + k + 1 > v.end() ? v.end() : it + k + 1);

    v.erase(start, end); //vector.erase(begin, end); btw, it doesn't delete "end"

    return v;
    // don’t forget to return something
}
int main()
{
    int n, j, k;
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result)
    {
        cout << x << endl;
    }
}