#include <cstdio>

class Solution {
public:
  int Fibonacci(int n) {
    if (n <= 1)
      return n;
    int a = 0, b = 1;
    for (int i = 0; i < n - 1; i++) {
      int c = a + b;
      a = b;
      b = c;
    }
    return b;
  }
};

int main(int argc, char const *argv[]) {

  {
    Solution s;
    printf("%d\n", s.Fibonacci(2));
    printf("%d\n", s.Fibonacci(3));
    printf("%d\n", s.Fibonacci(4));
  }
  return 0; }
