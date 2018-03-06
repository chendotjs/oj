#include <iostream>
using namespace std;

class Incr {
public:
  static int sum;
  static int N;
  Incr() {
    N++;
    sum += N;
  };
};

int Incr::sum = 0;
int Incr::N = 0;


class Solution {
public:
    int Sum_Solution(int n) {
      Incr::sum = 0;
      Incr::N = 0;
      Incr *p = new Incr[n];
      int r = Incr::sum;
      delete p;
      return r;
    }
};


int main(int argc, char const *argv[]) {
  auto r = Solution().Sum_Solution(100);
  cout << r << endl;
  r = Solution().Sum_Solution(10);
  cout << r << endl;
  return 0;
}
