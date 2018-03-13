#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int GetNumberOfK(vector<int> data, int k) {
    if (data.size() == 0)
      return 0;

    int first = GetFirstK(data, k, 0, data.size() - 1);
    int last = GetLastK(data, k, 0, data.size() - 1);

    if (first > -1 && last > -1)
      return last - first + 1;

    return 0;
  }

  int GetFirstK(vector<int> &data, int k, int start, int end) {
    if (start <= end) {
      int mid = start + (end - start) / 2;
      if (data[mid] == k) {
        if ((mid > 0 && data[mid - 1] != k) || mid == 0) {
          return mid;
        } else
          return GetFirstK(data, k, start, mid - 1);
      } else if (data[mid] < k) {
        return GetFirstK(data, k, mid + 1, end);
      } else {
        return GetFirstK(data, k, start, mid - 1);
      }
    }
    return -1;
  }

  int GetLastK(vector<int> &data, int k, int start, int end) {
    if (start <= end) {
      int mid = start + (end - start) / 2;
      if (data[mid] == k) {
        if ((mid < end && data[mid + 1] != k) || mid == end) {
          return mid;
        } else
          return GetLastK(data, k, mid + 1, end);
      } else if (data[mid] < k) {
        return GetLastK(data, k, mid + 1, end);
      } else {
        return GetLastK(data, k, start, mid - 1);
      }
    }
    return -1;
  }
};

int main(int argc, char const *argv[]) {
  {
    vector<int> vec ={1,2,3,3,3,3,4,5};
    cout << Solution().GetNumberOfK(vec, 3) << endl;
  }
  return 0;
}
