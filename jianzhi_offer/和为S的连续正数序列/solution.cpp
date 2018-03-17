#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> FindContinuousSequence(int sum) {
    vector<vector<int>> res;
    int a, b;
    for (int i = 1; i < 2 * sum; i++) {
      if ((2 * sum) % i == 0) {
        int j = 2 * sum / i;
        if (((i + j) & 0x01) == 0)  // 偶数
          continue;

        // cout << i << " " << j << endl;

        b = (i + j - 1) / 2;
        a = i - b;

        if (a < b && a > 0 && b > 0) {
          // cout << a << " " << b << endl;
          vector<int> vec;
          for (int x = a; x <= b; x++)
            vec.push_back(x);
          res.push_back(vec);
        }
      }
    }
    return res;
  }
};


int main(int argc, char const *argv[]) {
  {
    auto r = Solution().FindContinuousSequence(9);
  }

  {
    auto r = Solution().FindContinuousSequence(100);
  }
  return 0;
}
