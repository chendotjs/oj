#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int, int> M;
      vector<int> res(2);

      for (int i = 0; i < nums.size(); i++) {
        if (M.find(target - nums[i]) == M.end()) {
          M[nums[i]] = i;
        } else {
          res[0] = M[target - nums[i]];
          res[1] = i;
          break;
        }
      }
      return res;
    }
};

int main(int argc, char const *argv[]) {
  {
    vector<int> vec = {2, 7, 11, 15};
    auto r = Solution().twoSum(vec, 9);
    cout << r[0] << " " << r[1] << endl;
  }

  {
    vector<int> vec = {2, 7, 11, 15};
    auto r = Solution().twoSum(vec, 18);
    cout << r[0] << " " << r[1] << endl;
  }

  {
    vector<int> vec = {3, 2, 4};
    auto r = Solution().twoSum(vec, 6);
    cout << r[0] << " " << r[1] << endl;
  }

  {
    vector<int> vec = {3, 3};
    auto r = Solution().twoSum(vec, 6);
    cout << r[0] << " " << r[1] << endl;
  }
  return 0;
}
