#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (k < 1 || k > input.size())
      return vector<int>();
    multiset<int, greater<int>> mset;

    for (auto &i : input) {
      if (mset.size() < k) {
        mset.insert(i);
      } else {
        if (*mset.begin() >  i) {
          mset.erase(mset.begin());
          mset.insert(i);
        }
      }
    }

    vector<int> r(mset.begin(), mset.end());
    return r;
  }
};

int main(int argc, char const *argv[]) {
  {
    vector<int> vec = {4,5,1,6,2,7,3,8};
    auto r = Solution().GetLeastNumbers_Solution(vec, 4);
    r = r;
  }

  {
    vector<int> vec = {4,5};
    auto r = Solution().GetLeastNumbers_Solution(vec, 1);
    r = r;
  }
  return 0;
}
