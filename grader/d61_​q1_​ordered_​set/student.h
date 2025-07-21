#include <vector>
#include <unordered_set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    unordered_set<int> us;
    for (auto &e : A){
        v.push_back(e);
        us.insert(e);
    }
    for (auto &e : B){
        if (us.find(e) == us.end()){ // not found
            v.push_back(e);
            us.insert(e);
        }

    }
    // for (auto &e : us){
    //     v.push_back(e);
    // }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    unordered_set<int> b;

    for (auto &e : B){
        b.insert(e);
    }

    for (auto &e : A){
        if (b.find(e) != b.end()){ // found 
            v.push_back(e);
        }
    }

    return v;
}
