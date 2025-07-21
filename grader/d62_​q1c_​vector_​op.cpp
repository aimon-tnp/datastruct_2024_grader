#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> v;
    int n;
    std::cin >> n;
    for (int i = 0;i < n;i++){
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "pb"){
            int x;
            std::cin >> x;
            v.push_back(x);
        } else if (cmd == "sa"){
            sort(v.begin(), v.end());
        } else if (cmd == "sd"){
            sort(v.begin(), v.end(), std::greater<int>());
        } else if (cmd == "r"){
            reverse(v.begin(), v.end());
        } else if (cmd == "d"){
            int x;
            std::cin >> x;
            v.erase(v.begin() + x);
        }
    }

    for (int i = 0;i < v.size();i++){
        std::cout << v[i] << " ";
    }

    return 0;
}