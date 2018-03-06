#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
      map<int , int> M;
      for (auto & i : numbers) {
        M[i]++;
      }

      for (auto it = M.begin(); it != M.end(); it++) {
        if (it->second * 2 > numbers.size()) {
          return it->first;
        }
      }
      return 0;
    }
};
