#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 获得两个整形二进制表达位数不同的数量
     *
     * @param m 整数m
     * @param n 整数n
     * @return 整型
     */
    int countBitDiff(int m, int n) {
      unsigned int um = m;
      unsigned int un = n;
      unsigned res = um ^ un;
      int ans = 0;
      while (res != 0) {
        if (res & 0x01)
          ans++;
        res = res >> 1;
      }
      return ans;
    }
};

int main() {
  cout << "Hello world!" << endl;

  {
    Solution s;
    std::cout << s.countBitDiff(1999,2299) << endl;
  }
  {
    Solution s;
    std::cout << s.countBitDiff(100,100) << endl;
  }

  {
    Solution s;
    std::cout << s.countBitDiff(8,7) << endl;
  }

  {
    Solution s;
    std::cout << s.countBitDiff(1,2) << endl;
  }

  {
    Solution s;
    std::cout << s.countBitDiff(0,1) << endl;
  }

  return 0;
}

