#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  stack<int> S;
  bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    int j = 0;
    for (int i = 0; i < pushV.size(); i++) {
      S.push(pushV[i]);
      while (j < popV.size() && popV[j] == S.top()) {
        j++;
        S.pop();
      }
    }
    return S.empty();
  }
};

int main(int argc, char const *argv[]) {
  {
    std::vector<int> pushV = {1, 2, 3, 4};
    std::vector<int> popV = {3, 4, 1, 2};
    cout << Solution().IsPopOrder(pushV, popV);
  }

  {
    std::vector<int> pushV = {1, 2, 3, 4};
    std::vector<int> popV = {3, 4, 2, 1};
    cout << Solution().IsPopOrder(pushV, popV);
  }
  return 0;
}
