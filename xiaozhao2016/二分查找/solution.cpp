#include <iostream>
#include <vector>

using namespace std;

class BinarySearch {
public:
  int binsearch(const vector<int> &A, int left, int right, int val) {
    if (left > right)
      return -1;
    int mid = left + (right - left) / 2;
    if (A[mid] == val)
      return mid;
    else if (val < A[mid])
      return binsearch(A, left, mid - 1, val);
    else
      return binsearch(A, mid + 1, right, val);
  }
  int getPos(vector<int> A, int n, int val) {
    // write code here
    int first = binsearch(A, 0, n - 1, val);
    while (first > 0 && A[first - 1] == val)
      first--;
    return first;
  }
};

int main() {
  {
    BinarySearch s;
    vector<int> ivec = {1, 1, 3, 5, 7, 9};
    std::cout << s.getPos(ivec, ivec.size(), 1) << endl;
  }

  {
    BinarySearch s;
    vector<int> ivec = {1, 3, 5, 7, 9};
    std::cout << s.getPos(ivec, ivec.size(), 0) << endl;
  }
  {
    BinarySearch s;
    vector<int> ivec = {1, 3, 5, 7, 9};
    std::cout << s.getPos(ivec, ivec.size(), 7) << endl;
  }
  {
    BinarySearch s;
    vector<int> ivec = {1, 3, 5, 7, 9};
    std::cout << s.getPos(ivec, ivec.size(), 9) << endl;
  }
  {
    BinarySearch s;
    vector<int> ivec = {1, 3, 5, 7, 9};
    std::cout << s.getPos(ivec, ivec.size(), 8) << endl;
  }
  {
    BinarySearch s;
    vector<int> ivec = {1, 3, 5, 7, 9};
    std::cout << s.getPos(ivec, ivec.size(), 100) << endl;
  }
  return 0;
}
