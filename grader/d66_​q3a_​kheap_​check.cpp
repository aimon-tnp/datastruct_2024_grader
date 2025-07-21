#include <iostream>
#include <vector>

using namespace std;

int main(){
    int m;
    cin >> m;

    for (int i = 0; i < m; i++){
        int n, k;
        cin >> n >> k; // n = mSize
        vector<int> v(n);
        for (int j = 0; j < n; j++){
            cin >> v[j];
        }
        bool valid = true;

        for (int j = 1; j < n; j++){ // fix up!
            if (!valid){
                break;
            }

            // if (j == 0){
            //     continue;
            // }

            if (v[(j-1)/k] < v[j]){ // if parent < child -> not valid
                valid = false;
            }
        }

        if (valid){
            cout << "true";
        } else {
            cout << "false";
        }
        cout << endl;
    }

    return 0;
}