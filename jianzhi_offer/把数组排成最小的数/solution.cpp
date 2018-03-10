#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  static bool cmp(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    return sa + sb < sb + sa;
  }

  string PrintMinNumber(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), cmp);
    string answer;
    for (auto &s : numbers)
      answer += to_string(s);
    return answer;
  }
};
