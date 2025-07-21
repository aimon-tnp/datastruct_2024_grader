void replace(const T& x, list<T>& y) {
  //write your code here
  auto it = begin();
  while (it != end()){
    if (*it == x){
      for (auto &e : y){
        insert(it, e); 
      }
      erase(it);
    } else {
      it++;
    }
  }
}
