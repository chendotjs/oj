#include <iostream>
#include <cstdio>
#include <climits>

class Solution {
public:
    int reverse(int x) {
      bool flag = x < 0 ? true : false;
      if (x < 0)
        x = -x;

      long res = 0;
      while (x != 0) {
        int t = x % 10;
        res = res * 10 + t;
        x /= 10;
      }

      if (flag)
        res = -res;

      if (res > INT_MAX || res < INT_MIN)
          res = 0;
      return res;
    }
};
