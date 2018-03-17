#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
      if (data.size() == 0)
        *num1 = *num2 = 0;
      int resultXOR = 0;
      for (auto &i : data)
        resultXOR ^= i;

      int index = findFirstBit1(resultXOR);
      *num1 = *num2 = 0;
      int base = 0x01;
      while (index--)
        base = base << 1;

      for (auto &i : data) {
        if (judgeIs1Bit(base, i)) {
          *num1 ^= i;
        } else {
          *num2 ^= i;
        }
      }
    }

    int findFirstBit1(int resultXOR) {
      int cnt = 0;
      while ((0x01 & resultXOR) == 0) {
        resultXOR = resultXOR >> 1;
        cnt++;
      }
      return cnt;
    }

    bool judgeIs1Bit(int base, int num) {
      if ((num & base) == 0)
        return false;
      return true;
    }
};


int main(int argc, char const *argv[]) {
  {
    vector<int> data = {2,4,3,6,3,5,5,2};
    int num1, num2;
    Solution().FindNumsAppearOnce(data, &num1, &num2);
    cout << num1 << " " << num2 << endl;
  }
  return 0;
}
