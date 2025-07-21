#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> expectedSales(m);
    vector<int> accumulatedSales;
    for (auto &e : expectedSales){
        cin >> e;
    }

    set<pair<int, int> > orders;
    for (int i=0;i<n;i++){
        int cmd;
        cin >> cmd;
        if (cmd == 1){ // order
            int a,b;
            cin >> a >> b; // a = 1/2 (plathong/dotman), b (price) in range [1,1000]
            orders.insert(make_pair(b,a));

        } else { // cook
            if (accumulatedSales.empty()){
                accumulatedSales.push_back( (*orders.begin()).first );
            } else {
                accumulatedSales.push_back( *prev(accumulatedSales.end()) + (*orders.begin()).first );
            }

            orders.erase(orders.begin());
        }
    }

    for (auto &e : accumulatedSales){
        cout << e << " ";
    }

    cout << endl << endl;

    for (int i=0;i<expectedSales.size();i++){
        auto lower_it = lower_bound(accumulatedSales.begin(), accumulatedSales.end(), expectedSales[i]);
        if (lower_it == accumulatedSales.end()){ // not enough sales
            cout << "-1";
        } else {
            cout << distance(accumulatedSales.begin(), lower_it) + 1;
        }
        cout << " ";
    }

    return 0;
}