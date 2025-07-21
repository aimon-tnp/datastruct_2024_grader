#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<int, int> > ranges;

    for (int i=0;i<n;i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        ranges.push_back(make_pair(temp1, temp2));
    }
    sort(ranges.begin(), ranges.end());

    for (int i=0;i<m;i++){
        int temp;
        cin >> temp;
        bool found = false;

        auto it = lower_bound(ranges.begin(), ranges.end(), make_pair(temp, 0));

        if (temp >= (*it).first && temp <= (*it).second){
            found = true;
        } else if (temp >= (*prev(it)).first && temp <= (*prev(it)).second){
            found = true;
        }

        if (found){
            cout << "1 ";
        } else {
            cout << "0 ";
        }

    }


    return 0;
}