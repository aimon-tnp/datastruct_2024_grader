#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,w;
    cin >> n >> w;

    vector<int> numbers;
    for (int i=0;i<n;i++){
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    int times = n-w;
    if (times == 0){
        times = 1;
    }

    for (int i=0;i<times;i++){
        vector<int> sub_vector(numbers.begin() + i, numbers.begin() + i + w + 1);
        sort(sub_vector.begin(), sub_vector.end());
        cout << sub_vector[w/2] << " " ;
    }

    return 0;
}