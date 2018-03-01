#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> printMatrix(vector<vector<int>> matrix) {
    int start = 0;
    int row = matrix.size();
    int column = matrix[0].size();

    vector<int> result;
    while (start * 2 < row && start * 2 < column) {
      print(matrix, start, row, column, result);
      start++;
    }
    return result;
  }

  void print(const vector<vector<int>> &matrix, int start, int row, int column,
             vector<int> &result) {
    int endX = column - 1 - start;
    int endY = row - 1 - start;

    for (int i = start; i <= endX; i++) {
      result.push_back(matrix[start][i]);
    }
    if (start < endY) {
      for (int i = start + 1; i <= endY; i++) {
        result.push_back(matrix[i][endX]);
      }
    }

    if (start < endX && start < endY) {
      for (int i = endX - 1; i >= start; i--) {
        result.push_back(matrix[endY][i]);
      }
    }

    if (start + 1 < endY && start < endX) {
      for (int i = endY - 1; i >= start + 1; i--) {
        result.push_back(matrix[i][start]);
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
    };

    auto v = Solution().printMatrix(matrix);
    for (auto i : v)
      cout << i << " ";
    cout << endl;
  }

  {
    vector<vector<int>> matrix = {
        {1, 2, 3},

    };

    auto v = Solution().printMatrix(matrix);
    for (auto i : v)
      cout << i << " ";
    cout << endl;
  }

  {
    vector<vector<int>> matrix = {
        {1},{2}

    };

    auto v = Solution().printMatrix(matrix);
    for (auto i : v)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
