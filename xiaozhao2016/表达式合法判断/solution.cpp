#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

class ChkExpression {
public:
  stack<char> Q;

  bool isbrace(char c) {
    return c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}';
  }
  bool chkLegal(string A) {
    // write code here
    int len = A.size();
    for (int i = 0; i < len; i++) {
      char curr = A[i];
      if (isbrace(curr)) {
        if (curr == '(' || curr == '[' || curr == '{') {
          Q.push(curr);
        } else {
          Q.pop();
        }
      }
    }
    return Q.empty();
  }
};

int main(int argc, char const *argv[]) {
  {
    ChkExpression s;
    std::cout << s.chkLegal("[a+b*(5-4)]*{x+b+b*(({1+2)}}") << endl;
  }

  {
    ChkExpression s;
    std::cout << s.chkLegal("((([)))") << endl;
  }

  {
    ChkExpression s;
    std::cout << s.chkLegal("(((}[)))") << endl;
  }

  return 0;
}
