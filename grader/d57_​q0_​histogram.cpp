#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, int> vocab;

    for (int i=0;i<n;i++){
        string word;
        cin >> word;
        vocab[word]++;
    }

    for (auto &element : vocab){
        if (element.second > 1){
            cout << element.first << " " << element.second << endl;
        }
    }

    return 0;
}