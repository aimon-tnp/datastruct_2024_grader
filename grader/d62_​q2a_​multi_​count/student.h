#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    //write your code here
    CP::queue<T> temp = *this;
    std::map<T,int> m;

    while(!temp.empty()){
        m[temp.front()]++;
        temp.pop();
    }

    std::vector<std::pair<T,size_t>> ans;
    for (auto &e : k)
    {
        ans.push_back({e,m[e]});
    }
    return ans;
}

#endif
