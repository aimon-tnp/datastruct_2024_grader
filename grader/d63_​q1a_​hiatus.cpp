#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    cin >> n >> m;

    vector<pair<int, int> > date;

    for (int i = 0;i<n;i++){
        int year, month;
        cin >> year >> month;
        date.push_back(make_pair(year, month));
    }
    sort(date.begin(), date.end());

    // for (auto &element : date){
    //     cout << element.first << " " << element.second << endl;
    // }

    for (int i=0;i<m;i++){
        int year, month;
        cin >> year >> month;

        auto it = lower_bound(date.begin(), date.end(), make_pair(year, month));

        if (it == date.begin()){
            cout << "-1 -1 ";
        } else if (it == date.end()){
            cout << date.back().first << " " << date.back().second << " ";
        } else {
            if (*it == make_pair(year, month)){
                cout << "0 0 ";
            } else {
                cout << (*prev(it)).first << " " << (*prev(it)).second << " ";
            }
        }
    }

    return 0;
}