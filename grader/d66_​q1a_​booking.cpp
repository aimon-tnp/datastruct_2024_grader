#include <iostream>
// #include <map>
#include <set>
#include <vector>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m;
    cin >> n >> m;
    set<pair<string, string> > tickets; // set of available tickets (info1, info2)

    for (int i=0;i<n;i++){
        string info1, info2;
        cin >> info1 >> info2;
        tickets.insert(make_pair(info1, info2));
    }

    // for (auto &&i : tickets)
    // {
    //     cout << i.first << ": " << i.second << endl;
    // }
    
    for (int i=0;i<m;i++){
        int amount;
        cin >> amount;

        vector<pair<string, string> > buying;
        bool isSucceed = true;

        for (int j=0;j<amount;j++){ // initialize vector of wanted tickets
            string info1, info2;
            cin >> info1 >> info2;
            
            if (tickets.find(make_pair(info1, info2)) == tickets.end()){ // if any ticket doesn't exist -> false
                isSucceed = false;
            } else {
                buying.push_back(make_pair(info1, info2));
            }
        }

        if (isSucceed){
            for (auto &e : buying){ // delete wanted tickets from 'available tickets'
                tickets.erase(e);
            }
        }

        cout << (isSucceed ? "YES":"NO") << "\n";
    }

    return 0;
}