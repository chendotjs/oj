#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int FindGreatestSumOfSubArray(vector<int> array) {
    vector<int> vec(array.size());
    vec[0] = array[0];
    int result = vec[0];

    for (int i = 1; i < array.size(); i++) {
      vec[i] = max(array[i], array[i] + vec[i - 1]);
      if (vec[i] > result)
        result = vec[i];
    }
    return result;
  }
};


int main(int argc, char const *argv[]) {
  {
    vector<int> array = {6,-3,-2,7,-15,1,2,2};
    cout << Solution().FindGreatestSumOfSubArray(array) << endl;
  }
  return 0;
}
