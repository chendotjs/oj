#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
      stack<char> S;

      for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
          S.push(c);
        }
        if (c == ')' || c == '}' || c == ']') {
          if (S.empty())
            return false;
          if (c == ')' && S.top() != '(')
            return false;
          if (c == '}' && S.top() != '{')
            return false;
          if (c == ']' && S.top() != '[')
            return false;
          S.pop();
        }

      }
      return S.empty();
    }
};
int main(int argc, char const *argv[]) {
  cout << Solution().isValid("[[]]") << endl;
  cout << Solution().isValid("[()]") << endl;
  return 0;
}
