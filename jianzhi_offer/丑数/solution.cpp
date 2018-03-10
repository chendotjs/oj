#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int GetUglyNumber_Solution(int index) {
    if (index == 0)
      return 0;

    vector<int> result(index);
    result[0] = 1;
    int t2 = 0, t3 = 0, t5 = 0;
    for (int i = 1; i < index; i++) {
      result[i] = min(result[t2] * 2, min(result[t3] * 3, result[t5] * 5));
      if (result[i] == result[t2] * 2) t2++;
      if (result[i] == result[t3] * 3) t3++;
      if (result[i] == result[t5] * 5) t5++;
    }
    return result[index - 1];
  }
};


int main(int argc, char const *argv[]) {
  {
    cout << Solution().GetUglyNumber_Solution(0) << endl;
    cout << Solution().GetUglyNumber_Solution(1) << endl;
    cout << Solution().GetUglyNumber_Solution(2) << endl;
    cout << Solution().GetUglyNumber_Solution(3) << endl;
    cout << Solution().GetUglyNumber_Solution(4) << endl;
    cout << Solution().GetUglyNumber_Solution(5) << endl;
    cout << Solution().GetUglyNumber_Solution(10) << endl;
  }
  return 0;
}
