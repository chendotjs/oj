#include <vector>
using namespace std;

class Solution {
public:
  void reOrderArray(vector<int> &array) {
    vector<int> new_array;
    for (auto &i : array) {
      if (i % 2 == 1)
        new_array.push_back(i);
    }

    for (auto &i : array) {
      if (i % 2 == 0)
        new_array.push_back(i);
    }
    array.assign(new_array.begin(), new_array.end());
  }
};

int main(int argc, char const *argv[]) {

  vector<int> vec {1,2,3,4,5};
  Solution().reOrderArray(vec);
  return 0;
}
