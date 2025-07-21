#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> character(m,1);
    vector<int> temp_power(n);

    for (auto &e : temp_power){
        cin >> e;
    }

    map<int,int> power_frequency_tracking;
    power_frequency_tracking[1] = m;

    for (int i=0;i<n;i++){
        int power_type;
        cin >> power_type;
        if (character[power_type] < temp_power[i]){

            power_frequency_tracking[character[power_type]]--; // update power_frequency_tracking (decreasing)
            power_frequency_tracking[temp_power[i]]++; // update power_frequency_tracking (increasing the other one)

            if (power_frequency_tracking[character[power_type]] == 0){ // delete key if frequency == 0
                power_frequency_tracking.erase(character[power_type]);
            }

            

            character[power_type] = temp_power[i]; // update character itself

        }

        cout << (*power_frequency_tracking.begin()).first << " ";
    }

    
    return 0;
}