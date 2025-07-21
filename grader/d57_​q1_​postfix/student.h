#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>
#include <stack>

using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
  //WRITE YOUR CODE HERE


      
  //DON"T FORGET TO RETURN THE RESULT
  stack<int> operand;
  for (auto &e : v){
    if (e.first == 1){
      operand.push(e.second);
    } else if (e.first == 0){
      int n1 = operand.top(); // get 2 top elements
      operand.pop();
      int n2 = operand.top();
      operand.pop();

      int calculated; // opearate
      if (e.second == 0){
        calculated = n2 + n1;
      } else if (e.second == 1){
        calculated = n2 - n1;
      } else if (e.second == 2){
        calculated = n2 * n1;
      } else if (e.second == 3){
        calculated = n2 / n1;
      }

      operand.push(calculated); // push result back
    }
  }
  
  return operand.top();
}

#endif
