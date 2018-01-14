#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
  int minR(const vector<int> &rotateArray, int index1, int index2) {
    if (rotateArray[index1] < rotateArray[index2])
      return 0;

    if (index2 - index1 == 1)
      return index2;
    int mid = index1 + (index2 - index1) / 2;
    if (rotateArray[index1] == rotateArray[index2] && rotateArray[index1] == rotateArray[mid]) {
      for (int i = index1 + 1; i <= index2; i++) {
        if (rotateArray[i] < rotateArray[i - 1])
          return i;
      }
    }
    if (rotateArray[mid] >= rotateArray[index1]) {
      index1 = mid;
    } else if (rotateArray[index2] >= rotateArray[mid]) {
      index2 = mid;
    }
    return minR(rotateArray, index1, index2);
  }
  int minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.size() == 0)
      return 0;
    int index1 = 0;
    int index2 = rotateArray.size() - 1;
    int index =  minR(rotateArray, index1, index2);
    return rotateArray[index];
  }
};

int main(int argc, char const *argv[]) {
  {
    Solution s;
    vector<int> ivec{1, 2, 3, 4, 5};
    int ans = s.minNumberInRotateArray(ivec);
    printf("%d\n", ans); // 0
  }

  {
    Solution s;
    vector<int> ivec{1, 2, 3, 4, 5, 1};
    int ans = s.minNumberInRotateArray(ivec);
    printf("%d\n", ans); // 5
  }

  {
    Solution s;
    vector<int> ivec{3, 4, 5, 1, 2};
    int ans = s.minNumberInRotateArray(ivec);
    printf("%d\n", ans); // 3
  }

  {
    Solution s;
    vector<int> ivec{3, 3, 5, 1, 3};
    int ans = s.minNumberInRotateArray(ivec);
    printf("%d\n", ans); // 3
  }

  {
    Solution s;
    vector<int> ivec{3, 3, 3, 1, 3};
    int ans = s.minNumberInRotateArray(ivec);
    printf("%d\n", ans); // 3
  }

  {
    Solution s;
    vector<int> ivec{1, 1, 1, 1, 1, 2, 0, 1, 1, 1, 1};
    int ans = s.minNumberInRotateArray(ivec);
    printf("%d\n", ans); // 3
  }

  return 0;
}
