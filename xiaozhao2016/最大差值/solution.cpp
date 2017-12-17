#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class LongestDistance {
public:
  int max(int a, int b) { return a > b ? a : b; }
  int getDis(vector<int> A, int n) {
    // write code here
    vector<int> res(A.size());
    int mini = A[0];
    res[0] = A[1] - A[0];
    for (int i = 1; i < A.size(); i++) {
      res[i] = max(res[i - 1], A[i] - mini);
      if (A[i] < mini) {
        mini = A[i];
      }
    }
    int ans = res[1];
    for (int i = 1; i < A.size(); i++) {
      if (res[i] > ans)
        ans = res[i];
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  {

    vector<int> iv = {1, 2, 4, 6, 8, 12, 15};
    LongestDistance s;
    cout << s.getDis(iv, iv.size()) << endl;
  }

  {

    vector<int> iv = {11, 2, -4, 6, 8, 12, 15};
    LongestDistance s;
    cout << s.getDis(iv, iv.size()) << endl;
  }

  {

    vector<int> iv = {15, 9, 8, 5, 4, 1};
    LongestDistance s;
    cout << s.getDis(iv, iv.size()) << endl;
  }

  return 0;
}
