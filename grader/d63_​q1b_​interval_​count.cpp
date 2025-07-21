#include <iostream>
// #include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> sample;
    for (int i=0;i<n;i++){
        int temp;
        cin >> temp;
        sample.push_back(temp);
    }
    sort(sample.begin(), sample.end());

    for (int i=0;i<m;i++){
        int temp;
        cin >> temp;

        int lower = temp - k;
        int upper = temp + k;

        auto lower_it = lower_bound(sample.begin(), sample.end(), lower);
        auto upper_it = upper_bound(sample.begin(), sample.end(), upper);

        int result = distance(lower_it, upper_it);
        cout << result << " ";
    }

    return 0;
}