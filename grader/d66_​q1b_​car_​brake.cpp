#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m,k,maxday = 0;
    cin >> n >> m >> k; // starting velocity = k;
    map<int,int> brakes;

    while (n--){
        int t,d;
        cin >> t >> d;
        brakes[t] = d;
        if (t > maxday){
            maxday = t;
        }
    }

    // calculating speed at days;
    vector<int> velocity(maxday+1,0);
    for (int i = 0; i < velocity.size(); i++){
        if (brakes.find(i) != brakes.end()){ // found (brake!)
            k -= brakes[i];
        }
        if (k < 0){
            k = 0;
        }
        velocity[i] += k;
    }

    // for (int i = 0; i < velocity.size(); i++){
    //     cout << "DAY " << i << ": " << velocity[i] << endl;
    // }
    
    while (m--){
        int a,q;
        cin >> a >> q;
        if (a == 1){
            cout << velocity[q] << endl;
        } else if (a == 2){
            int count = 0;
            for (auto &e : velocity){
                if (e >= q){
                    count++;
                } else {
                    break;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}