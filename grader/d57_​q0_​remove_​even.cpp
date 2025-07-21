#include <iostream>
#include <vector>
using namespace std;
void remove_even(vector<int> &v,int a,int b) {
  //write your code only in this function
  vector<int> result;
  for (int i = v.size() - 1;i >= 0;i--){
    if (i <= b && i >= a){ // in [a,b] range
        if (i % 2 != 0){
            result.insert(result.begin(), v[i]);
        }
    } else {
        result.insert(result.begin(), v[i]);
    }
  }
  v = result;

}
int main() {
  //read input
  int n,a,b;
  cin >> n;
  vector<int> v;
  for (int i = 0;i < n;i++) {
    int c;
    cin >> c;
    v.push_back(c);
}
cin >> a >> b;
  //call function
  remove_even(v,a,b);
  //display content of the vector
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << endl;
}