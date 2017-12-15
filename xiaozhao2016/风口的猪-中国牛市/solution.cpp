#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  /**
   * 计算你能获得的最大收益
   *
   * @param prices Prices[i]即第i天的股价
   * @return 整型
   */
  int max(int a, int b) { return a > b ? a : b; }
  int min(int a, int b) { return a < b ? a : b; }
  int dpl[101];
  int dpr[101];
  int calculateMax(vector<int> prices) {
    int ans = 0;
    int length = prices.size();

    dpl[0] = 0;
    int minp = prices[0];
    for (int i = 1; i < length; i++) {
      dpl[i] = max(dpl[i - 1], prices[i] - minp);
      if (prices[i] < minp) {
        minp = prices[i];
      }
    }

    dpr[length - 1] = 0;
    int maxp = prices[length - 1];
    for (int i = length - 2; i >= 0; i--) {
      dpr[i] = max(dpr[i + 1], maxp - prices[i]);
      if (maxp < prices[i]) {
        maxp = prices[i];
      }
    }

    for (int i = 0; i < length; i++) {
      if (dpr[i] + dpl[i] > ans) {
        ans = dpr[i] + dpl[i];
      }
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  {
    vector<int> vec = {3, 8, 5, 1, 7, 8};
    std::cout << s.calculateMax(vec) << endl;
  }

  {
    vector<int> vec = {9, 8, 7, 6, 5, 4};
    std::cout << s.calculateMax(vec) << endl;
  }

  {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    std::cout << s.calculateMax(vec) << endl;
  }
  return 0;
}
