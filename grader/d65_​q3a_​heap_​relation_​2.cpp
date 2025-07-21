#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int findrelation(long long S, long long a, long long b)
{
    bool related = false;
    long long lowernode = max(a,b), highernode = min(a,b);
    int depth1 = 0, depth2 = 0; // 1 -> lower, 2 -> higher

    while (lowernode > 0){
        long long parent = (lowernode - 1) / S;
        depth1++;
        if (parent == highernode){
            if (depth1 == 1){
                return 1;
            } else{
                related = true;
                break;
            }
            
        }
        lowernode = parent;
    }

    while (highernode > 0){
        depth2++;
        highernode = (highernode - 1) / S;
    }

    // if (related && abs(depth1 - depth2) == 1){
    //     return 1;
    // }
    if (related){
        return 2;
    }
    if (!related && depth1 != depth2){
        return 3;
    }
    if (!related && depth1 == depth2){
        return 4;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long S, a, b;
    cin >> n;
    while (n--)
    {
        cin >> S >> a >> b;
        cout << findrelation(S, a, b) << " ";
    }
    cout << endl;
}