#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int StrToInt(string str) {
    if (str.size() == 0)
      return 0;
    int sign = 1;
    int start = 0;
    int res = 0;
    if (str[0] == '+') {
      sign = 1;
      start = 1;
    } else if (str[0] == '-' ) {
      sign = -1;
      start = 1;
    }

    for (int i = start; i < str.size(); i++) {
      char c = str[i];
      if (isdigit(c)) {
        res = res * 10 + c - '0';
      } else
        return 0;
    }
    return res * sign;
  }
};


int main(int argc, char const *argv[]) {
  cout << Solution().StrToInt("123") << endl;
  cout << Solution().StrToInt("-123") << endl;
  cout << Solution().StrToInt("+123") << endl;
  cout << Solution().StrToInt("+12d3") << endl;
  return 0;
}
