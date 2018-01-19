#include <iostream>
#include <cstdio>


class Solution {
public:
     int  NumberOf1(int n) {
       int cnt = 0;
       unsigned int un = (unsigned int)(n);
       while (un) {
         if (un & 0x01)
          cnt++;
         un = un >> 1;
       }
       return cnt;
     }
};

int main(int argc, char const *argv[]) {
  {
    Solution s;
    printf("%d\n", s.NumberOf1(0));
    printf("%d\n", s.NumberOf1(1));
    printf("%d\n", s.NumberOf1(2));
    printf("%d\n", s.NumberOf1(8));
    printf("%d\n", s.NumberOf1(7));
    printf("%d\n", s.NumberOf1(-1));
    printf("%d\n", s.NumberOf1(-2));
    printf("%d\n", s.NumberOf1(-3));
    printf("%d\n", s.NumberOf1(-4));
  }
  return 0;
}
