#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, m, start;
    cin >> n >> m >> start;
    map<int, int> accumulationRate;
    accumulationRate[0] = start;

    for (int i=0;i<n;i++){
        int date, rate;
        cin >> date >> rate;
        accumulationRate[date] = rate;
    }

    vector<long long> money(100001);
    money[0] = start;
    for (int i=1;i <= 100000;i++){
        if (accumulationRate.find(i) != accumulationRate.end()){ // changes found
            start = accumulationRate[i];
        }
        money[i] = money[i-1] + start;
    }

    for (int i=0;i<m;i++){
        int price, date;
        cin >> price >> date;

        // auto lower_it = lower_bound(money.begin(), money.end(), price);
        // cout << lower_it - money.begin() << " ";

        if (price <= money[date]){ // enough money
            cout << lower_bound(money.begin(), money.end(), price) - money.begin() << " ";
        } else { // not enough money 
            cout << lower_bound(money.begin(), money.end(), price + money[date]) - money.begin() << " ";
        }
    }

    return 0;
}