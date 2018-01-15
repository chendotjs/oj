class Solution {
public:
#define N 101
  int result[N];
  int jumpFloor(int number) {
    result[1] = 1;
    result[2] = 2;
    for (int i = 3; i <= number; i++) {
      result[i] = result[i - 1] + result[i - 2];
    }
    return result[number];
  }
};
