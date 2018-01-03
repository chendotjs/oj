#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  bool Find(int target, vector<vector<int>> array) {
    bool flag = false;
    int row = 0;
    int col = array[0].size() - 1;
    while (row <= array.size() - 1 && col >= 0) {
      if (target == array[row][col]) {
        flag = true;
        return flag;
      } else if (target < array[row][col]) {
        col--;
      } else {
        row++;
      }
    }
    return flag;
  }
};

int main(int argc, char const *argv[]) {

  {
    Solution s;
    vector<vector<int>> ivec = {
        {1, 2, 5, 6}, {2, 3, 7, 8}, {4, 7, 9, 10}, {6, 8, 12, 20}};
    bool r = s.Find(7, ivec); // true
    cout << r << endl;
  }

  {
    Solution s;
    vector<vector<int>> ivec = {
        {1, 2, 5, 6}, {2, 3, 7, 8}, {4, 7, 9, 10}, {6, 8, 12, 20}};
    bool r = s.Find(11, ivec); // false
    cout << r << endl;
  }
  return 0;
}
