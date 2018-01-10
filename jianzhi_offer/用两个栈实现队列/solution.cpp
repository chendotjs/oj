#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  void push(int node) { stack1.push(node); }

  int pop() {
    if (stack2.empty() == true) {
      while (stack1.empty() == false) {
        int tmp = stack1.top();
        stack1.pop();
        stack2.push(tmp);
      }
    }
    int ret = stack2.top();
    stack2.pop();
    return ret;
  }

private:
  stack<int> stack1;
  stack<int> stack2;
};

int main(int argc, char const *argv[]) {
  {
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.pop() << " ";
    s.push(4);
    std::cout << s.pop() << " ";
    std::cout << s.pop() << " ";
    std::cout << s.pop() << " ";
    std::cout << std::endl;
  }
  return 0;
}
