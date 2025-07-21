#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;

    map<string, int> name;

    for (int i = 0;i < n;i++){
        string temp;
        cin >> temp;
        name[temp]++;
    }

    string target;
    int highest_value = 0;
    for (auto &element : name){
        if (element.second >= highest_value){
            target = element.first;
            highest_value = element.second;
        }
    }
    cout << target << " " << highest_value;
    return 0;
}