#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


class MaxInnerRec {
  #define LENGTH 501
public:
  int max(int a, int b) {return a > b ? a : b;}
  int area(const vector<int> &A, int begi, int endi) {
    int mini = A[begi];
    for (int i = begi; i <= endi; i++) {
      if (A[i] < mini)
        mini = A[i];
    }
    return mini * (endi - begi + 1);
  }
  int dp[LENGTH];
  int countArea(vector<int> A, int n) {
    // write code here
    memset(dp, 0, sizeof(dp));
    dp[0] = A[0];

    for (int i = 1; i < n; i++) {
      int maxi = A[i];
      for (int j = 0; j < i; j++) {
        maxi = max(area(A, j, i), maxi);
      }
      dp[i] = max(maxi, dp[i - 1]);
    }
    return dp[n - 1];
  }
};

int main() {
  cout << "Hello world!" << endl;
  {
    vector<int> ivec{2,7,9,4,1};
    MaxInnerRec s;
    std::cout << s.countArea(ivec, ivec.size()) << endl;
  }

  {
    vector<int> ivec{2};
    MaxInnerRec s;
    std::cout << s.countArea(ivec, ivec.size()) << endl;
  }

  {
    vector<int> ivec{2,2,2,2};
    MaxInnerRec s;
    std::cout << s.countArea(ivec, ivec.size()) << endl;
  }

    {
    vector<int> ivec{2,2,1200,2};
    MaxInnerRec s;
    std::cout << s.countArea(ivec, ivec.size()) << endl;
  }
  return 0;
}

