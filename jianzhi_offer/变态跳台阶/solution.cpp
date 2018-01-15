#include <cstdio>

class Solution {
public:
  int jumpFloorII(int number) {
    number--;
    int ans = 1;
    int r = 2;
    while (number != 0) {
      if (number & 0x01)
        ans *= r;
      r *= r;
      number = number >> 1;
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  for (int i = 1; i < 10; i++) {
    printf("%d\n", s.jumpFloorII(i));
  }
  return 0;
}
