#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string LeftRotateString(string str, int n) {
    if (str.size() == 0)
      return str;

    Reverse(str, 0, n - 1);
    Reverse(str, n, str.size() - 1);
    Reverse(str, 0, str.size() - 1);

    return str;
  }

  void Reverse(string &str, int ahead, int behind) {
    if (ahead >= behind)
      return;
    while (ahead < behind) {
      char temp = str[ahead];
      str[ahead] = str[behind];
      str[behind] = temp;

      ahead++;
      behind--;
    }
  }
};


int main(int argc, char const *argv[]) {
  {
    string str("abcXYZdef");
    cout << Solution().LeftRotateString(str, 3) << endl;
  }

  {
    string str("abcXYZdef");
    cout << Solution().LeftRotateString(str, 9) << endl;
  }
  return 0;
}
