#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> FindNumbersWithSum(vector<int> array, int sum) {
    vector<int> result(2);
    bool found = false;

    int before = 0;
    int after = array.size() - 1;

    while (before < after) {
      int s = array[before] + array[after];
      if (s == sum) {
        result[0] = array[before];
        result[1] = array[after];
        found = true;
        break;
      } else if (s > sum) {
        after--;
      } else {
        before++;
      }
    }
    if (!found)
      return vector<int>();
    return result;
  }
};


int main(int argc, char const *argv[]) {
  {
    vector<int> vec ={1,2,4,7,11,15};
    auto r = Solution().FindNumbersWithSum(vec, 15);
    cout << r[0] << r[1] << endl;
  }
  return 0;
}
