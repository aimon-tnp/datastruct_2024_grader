#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main(){
    int n,m,a;
    cin >> n >> m >> a;
    map<int, int> types;
    vector<map<int, int> > bids(n+1); // { {id1: bid1, id2: bid2} } (index == type)

    for (int i=1;i<=n;i++){
        int temp;
        cin >> temp;
        types[i] = temp; // types = {type : amount,...}
    }

    for (int i=0;i<a;i++){ // collecting info
        char cmd;
        cin >> cmd;
        if (cmd == 'B'){
            int id, type, bid;
            cin >> id >> type >> bid;
            bids[type][id] = bid;

        } else if (cmd == 'W'){
            int id, type;
            cin >> id >> type;
            bids[type].erase(id);

        }
    }

    map<int, set<int> > each_id_wins; // {id1: {type1, type2},... }
    for (int i=1;i<=m;i++){
        set<int> temp;
        each_id_wins[i] = temp;
    }
    for (int i=1;i<=n;i++){
        int current_type = i;
        int amount = types[current_type];

        priority_queue<pair<int,int> > pq;
        for (auto &e : bids[current_type]){ // create priority_queue for selecting highest bid
            int id = e.first;
            int bid = e.second;
            pq.push(make_pair(bid, id));
        }

        while (amount > 0 && !pq.empty()){
            auto winner_info = pq.top();
            pq.pop();
            int bid = winner_info.first;
            int id = winner_info.second;

            each_id_wins[id].insert(current_type);

            amount--;
        }
        
    }

    for (auto &e : each_id_wins){
        if (e.second.empty()){
            cout << "NONE";
        } else {
            for (auto &inset : e.second){
                cout << inset << " ";
            }
        }

        // cout << e.first << ": {";
        // for (auto &inset : e.second){
        //     cout << inset << " ";
        // }
        // cout << "}" << endl;

        cout << "\n";
    }
    
    return 0;
}