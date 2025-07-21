#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    cin >> n >> m;

    unordered_map<int, int> id_sales;
    set<pair<int, int> > sales_id;
    for (int i=0;i<n;i++){
        int temp;
        cin >> temp;
        id_sales[temp] = 0;
        // sales_id.insert(make_pair(0,temp));
    }

    for (int i=0;i<m;i++){
        int cmd;
        cin >> cmd;
        if (cmd == 1){
            int id, sales;
            cin >> id >> sales;
            if (id_sales.find(id) != id_sales.end()){ // id exists (our product!)
                // + in set, map
                sales_id.erase(make_pair(id_sales[id], id));
                id_sales[id] += sales;
                sales_id.insert(make_pair(id_sales[id], id));
                
            }

        } else if (cmd == 2){ // checking 'k' 
            int k;
            cin >> k;
            // auto lower_it = lower_bound(sales_id.begin(), sales_id.end(), make_pair(k,0));
            auto lower_it = sales_id.lower_bound(make_pair(k,0));
            if (lower_it == sales_id.begin()){
                cout << "NONE" << "\n";
            } else {
                --lower_it;
                if ((*lower_it).first == 0){
                    cout << "NONE" << "\n";
                } else {
                    cout << (*lower_it).second << "\n";
                }
            }
        }

        // cout << endl;
        // for (auto &e : sales_id){
        //     cout << "s: " << e.first << " , id: " << e.second << endl;
        // }
    }

    return 0;
}