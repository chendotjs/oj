#include <iostream>
using namespace std;

class Solution {
public:
  double Power(double base, int exponent) {
    int n = base;
    bool negative = exponent < 0 ? true : false;
    exponent = exponent > 0 ? exponent : -exponent;
    double ans = 1;
    while (exponent) {
      if (exponent & 0x01)
        ans *= n;
      exponent = exponent >> 1;
      n *= n;
    }
    return negative ? 1.0 / ans : ans;
  }
};

int main(int argc, char const *argv[]) {

  cout << Solution().Power(3, 2) << endl;
  cout << Solution().Power(3, 5) << endl;
  cout << Solution().Power(2, 5) << endl;
  cout << Solution().Power(2, 0) << endl;
  cout << Solution().Power(2, 1) << endl;

  cout << Solution().Power(2, -1) << endl;
  cout << Solution().Power(3, -2) << endl;
  cout << Solution().Power(-3, -2) << endl;
  cout << Solution().Power(-3, -3) << endl;

  return 0;
}
