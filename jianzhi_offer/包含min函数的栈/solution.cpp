#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  stack<int> datastack;
  stack<int> minstack;
  int min_ele;

  void push(int value) {
    datastack.push(value);
    if (minstack.size() == 0 || value < min_ele) {
      min_ele = value;
    }
    minstack.push(min_ele);
  }
  void pop() {
    datastack.pop();
    minstack.pop();
  }
  int top() { return datastack.top(); }
  int min() { return minstack.top(); }
};
