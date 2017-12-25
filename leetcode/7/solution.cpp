#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
  int abs(int x) { return x > 0 ? x : -x; }
  int reverse(int x) {
    int flag;
    flag = x >= 0 ? 1 : -1;
    x = abs(x);

    int ans = 0;

    while (x != 0) {
      if (INT_MAX / 10 >= ans && INT_MAX - ans * 10  >= (x % 10))
        ans = ans * 10 + (x % 10);
      else {
        ans = 0;
        break;
      }
      x /= 10;
    }

    return ans * flag;
  }
};

int main() {
  {
    Solution s;
    int ans = s.reverse(123);
    cout << ans << endl;
  }

  {
    Solution s;
    int ans = s.reverse(-123);
    cout << ans << endl;
  }

  {
    Solution s;
    int ans = s.reverse(120);
    cout << ans << endl;
  }

  {
    Solution s;
    int ans = s.reverse(-120);
    cout << ans << endl;
  }

  {
    Solution s;
    int ans = s.reverse(1534236469);
    cout << ans << endl;
  }
  return 0;
}

