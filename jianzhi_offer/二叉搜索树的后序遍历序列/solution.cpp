#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool VerifySquenceOfBST(vector<int> sequence) {
    int length = sequence.size();
    int i = 0;

    if (length == 0)
      return false;
    if (length == 1)
      return true;

    int root = sequence[length - 1];
    for (; i < length - 1; i++) {
      if (sequence[i] > root) {
        break;
      }
    }

    int j = i;
    for (; j < length - 1; j++) {
      if (sequence[j] < root)
        return false;
    }

    bool left = true;
    if (i > 0)
      left = VerifySquenceOfBST(
          vector<int>(sequence.begin(), sequence.begin() + i));

    bool right = true;
    if (j > i)
      right = VerifySquenceOfBST(
          vector<int>(sequence.begin() + i, sequence.begin() + j));

    return right && left;
  }
};

int main(int argc, char const *argv[]) {
  {
    vector<int> v = {5, 7, 6, 9, 11, 10, 8};
    cout << Solution().VerifySquenceOfBST(v) << endl;
  }

  {
    vector<int> v = {7, 4, 6, 5};
    cout << Solution().VerifySquenceOfBST(v) << endl;
  }

  {
    vector<int> v = {1, 2, 3, 4};
    cout << Solution().VerifySquenceOfBST(v) << endl;
  }

  {
    vector<int> v = {4, 3, 2, 1};
    cout << Solution().VerifySquenceOfBST(v) << endl;
  }

  return 0;
}
