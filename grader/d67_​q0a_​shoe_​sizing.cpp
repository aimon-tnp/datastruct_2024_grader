#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    set<int> A;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        A.insert(temp);
    }

    for (int i = 0; i < m; i++)
    {
        int wanted_size;
        cin >> wanted_size;

        auto lower = A.lower_bound(wanted_size);

        if (lower == A.end()){ // all element are smaller than wanted size
            cout << *prev(lower) << " ";
        } else if (lower == A.begin()){ // all element are bigger than wanted size
            cout << *lower << " ";
        } else { // wanted size is in A's range
            int atleast = *lower;
            int smaller = *prev(lower);

            if (abs(atleast - wanted_size) <= abs(smaller - wanted_size)){ // same difference, bigger one is more nearer
                cout << atleast << " ";
            } else { // small one is more nearer
                cout << smaller << " ";
            }
        }
    }
    return 0;
}