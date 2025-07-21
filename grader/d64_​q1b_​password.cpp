#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n,m,l;
    cout << "input n,m,l";
    cin >> n >> m >> l;

    vector<int> steps;
    for (int i=0;i<l;i++){
        int temp;
        cin >> temp;
        steps.push_back(temp);
    }

    set<string> encrypted;
    for (int i=0;i<n;i++){
        string temp_password;
        cin >> temp_password;
        encrypted.insert(temp_password);
    }

    for (int i=0;i<m;i++){
        string input;
        cin >> input;
        for (int letter_index=0;letter_index<l;letter_index++){
            input[letter_index] = ((input[letter_index] - 'a' + steps[letter_index]) % 26) + 'a';
        }
        if (encrypted.find(input) == encrypted.end()){
            cout << "Unknown";
        } else {
            cout << "Match";
        }
        cout << "\n";
    }
    return 0;
}