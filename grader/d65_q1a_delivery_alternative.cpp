#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> expectedSales(m);
    vector<int> accumulatedSales;
    for (auto &e : expectedSales){
        cin >> e;
    }

    queue<int> plathong1;
    queue<int> dotman2;

    for (int i=0;i<n;i++){
        int cmd;
        cin >> cmd;
        if (cmd == 1){ // placing order (categorize queue by application)
            int app,price;
            cin >> app >> price;
            if (app == 1){ // plathong1
                plathong1.push(price);
            } else {
                dotman2.push(price);
            }

        } else { // cooking (removing order and calculating accumulative money)
            int fromWhichApp;

            if (plathong1.empty()){
                fromWhichApp = 2;
            } else if (dotman2.empty()){
                fromWhichApp = 1;
            } else { // comparing front of both queue -> proceed with cheaper one.
                if (plathong1.front() <= dotman2.front()){
                    fromWhichApp = 1;
                } else if (plathong1.front() > dotman2.front()){
                    fromWhichApp = 2;
                }
            }
            
            if (accumulatedSales.empty()){ // accumulatedSales is empty
                if (fromWhichApp == 1){
                    accumulatedSales.push_back(plathong1.front());
                    plathong1.pop();
                } else if (fromWhichApp == 2){
                    accumulatedSales.push_back(dotman2.front());
                    dotman2.pop();
                }
            } else { // accumulatedSales is not empty
                if (fromWhichApp == 1){
                    accumulatedSales.push_back(*prev(accumulatedSales.end()) + plathong1.front());
                    plathong1.pop();
                } else if (fromWhichApp == 2){
                    accumulatedSales.push_back(*prev(accumulatedSales.end()) + dotman2.front());
                    dotman2.pop();
                }
            }

        }
    }

    // for (auto &e : accumulatedSales){
    //     cout << e << " ";
    // }

    // cout << endl << endl;

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