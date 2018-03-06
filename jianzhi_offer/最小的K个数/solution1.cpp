#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void swap(vector<int> &array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }

  int partition(vector<int> &array, int start, int end) {
    if (start >= end)
      return start;

    int i = start;
    int j = end + 1;
    if (start < end) {
      do {
        do i++; while (i <= end && array[i] < array[start]);
        do j--; while (array[j] > array[start]);
        if (i < j)
          swap(array, i, j);
      } while (i < j);
      swap(array, start, j);
    }
    return j;
  }

  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (k < 1 || k > input.size())
      return vector<int>();

    int start = 0;
    int end = input.size() - 1;
    int idx = partition(input, start, end);

    while (idx != k - 1) {
      if (idx > k - 1) {
        end = idx - 1;
        idx = partition(input, start, end);
      } else {
        start = idx + 1;
        idx = partition(input, start, end);
      }
    }
    vector<int> result(input.begin(), input.begin() + k);
    sort(result.begin(), result.end());
    return result;
  }
};

int main(int argc, char const *argv[]) {
  {
    vector<int> vec = {4,5,1,6,2,7,3,8};
    auto r = Solution().GetLeastNumbers_Solution(vec, 4);
    r = r;
  }

  {
    vector<int> vec = {4,5};
    auto r = Solution().GetLeastNumbers_Solution(vec, 1);
    r = r;
  }
  return 0;
}
