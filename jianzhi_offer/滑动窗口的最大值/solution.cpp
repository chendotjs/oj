#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
    vector<int> res;
    deque<int> index;
    if (num.size() < size || size < 1)
      return res;
    for (int i = 0; i < size; i++) {
      while (index.empty() == false && num[i] >= num[index.back()]) {
        index.pop_back();
      }
      index.push_back(i);
    }

    for (int i = size; i < num.size(); i++) {
      res.push_back(num[index.front()]);
      while (index.empty() == false && num[i] >= num[index.back()]) {
        index.pop_back();
      }
      if (!index.empty() && i - index.front() >= size) {
        index.pop_front();
      }
      index.push_back(i);
    }
    res.push_back(num[index.front()]);
    return res;
  }
};

int main(int argc, char const *argv[]) {
  {
    vector<int> vec = {2, 3, 4, 2, 6, 2, 5, 1};
    auto res = Solution().maxInWindows(vec, 3);
  }

  {
    vector<int> vec = {10, 9, 8, 100, 4, 5, 6};
    auto res = Solution().maxInWindows(vec, 3);
  }
  return 0;
}
