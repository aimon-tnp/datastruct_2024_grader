#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,w;
    cin >> n >> w;
    vector<int> numbers(n);
    for (auto &e : numbers){
        cin >> e;
    }

    multiset<int> lower;
    multiset<int> upper;

    for (int i=0;i < w + 1;i++){ // inserting first window
        if (lower.empty() || numbers[i] <= *lower.rbegin()){ // inserting
            lower.insert(numbers[i]);
        } else {
            upper.insert(numbers[i]);
        }

        while (lower.size() - upper.size() != 1 && lower.size() != upper.size()){ // balancing (lower = n + 1, upper = n)
            if (lower.size() - 1 > upper.size()){
                upper.insert(*lower.rbegin());
                lower.erase(--lower.end());
            } else if (upper.size() > lower.size() - 1){
                lower.insert(*upper.begin());
                upper.erase(upper.begin());
            }
        }
    }

    // for (auto &e : lower){
    //     cout << e << " ";
    // }
    // cout << ":";
    // for (auto &e : upper){
    //     cout << e << " ";
    // }
    // cout << endl << endl;

    cout << *lower.rbegin() << " ";
    
    for (int i = 1;i <= n - w - 1;i++){
        // remove -> insert -> balance
        int toRemove = numbers[i - 1];
        int toInsert = numbers[i + w];

        if (toRemove > *lower.rbegin()){ // remove
            upper.erase(upper.find(toRemove));
        } else {
            lower.erase(lower.find(toRemove));
        }

        if (toInsert > *lower.rbegin()){
            upper.insert(toInsert);
        } else {
            lower.insert(toInsert);
        }

        while (lower.size() - upper.size() != 1 && lower.size() != upper.size()){ // balancing (lower = n + 1, upper = n)
            if (lower.size() - 1 > upper.size()){
                upper.insert(*lower.rbegin());
                lower.erase(--lower.end());
            } else if (upper.size() > lower.size() - 1){
                lower.insert(*upper.begin());
                upper.erase(upper.begin());
            }
        }

        // for (auto &e : lower){
        //     cout << e << " ";
        // }
        // cout << ":";
        // for (auto &e : upper){
        //     cout << e << " ";
        // }
        // cout << endl << endl;

        cout << *lower.rbegin() << " ";

    }
    return 0;
}