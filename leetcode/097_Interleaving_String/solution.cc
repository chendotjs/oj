#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Time Limit Exceeded
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size())
      return false;
    return isInterleave(s1, s2, s3, s1.size() - 1, s2.size() - 1, s3.size() -
1);
  }
  bool isInterleave(string &s1, string &s2, string &s3, int e1, int e2,
                    int e3) {
    bool flag1 = false;
    bool flag2 = false;

    if (e1 == -1 && e2 == -1) {
      return true;
    }

    if (e1 >= 0 && s3[e3] == s1[e1]) {
      flag1 = isInterleave(s1, s2, s3, e1 - 1, e2, e3 - 1);
    }

    if (e2 >= 0 && s3[e3] == s2[e2]) {
      flag2 = isInterleave(s1, s2, s3, e1, e2 - 1, e3 - 1);
    }

    return flag1 || flag2;
  }
};
*/

/**
 * dp[i][j] means s1[0..i] and s2[0..j] can form s3[0..i+j+1]
 * @param  s1 [description]
 * @param  s2 [description]
 * @param  s3 [description]
 * @return    [description]
 */
class Solution {
#define OFFSET 1
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size())
      return false;

    vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
    dp[- 1 + OFFSET][- 1 + OFFSET] = true; // "" and ""

    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] == s3[i]) {
        dp[i + OFFSET][-1 + OFFSET] = true;
      } else
        break;
    }

    for (int i = 0; i < s2.size(); i++) {
      if (s2[i] == s3[i]) {
        dp[-1 + OFFSET][i + OFFSET] = true;
      } else
        break;
    }

    for (int i = 0; i < s1.size(); i++) {
      for (int j = 0; j < s2.size(); j++) {
        if (s2[j] == s3[i + j + 1]) {
          dp[i + OFFSET][j + OFFSET] =
              dp[i + OFFSET][j + OFFSET] || dp[i + OFFSET][j - 1 + OFFSET];
        }
        if (s1[i] == s3[i + j + 1]) {
          dp[i + OFFSET][j + OFFSET] =
              dp[i + OFFSET][j + OFFSET] || dp[i - 1 + OFFSET][j + OFFSET];
        }
      }
    }
    return dp[s1.size() - 1 + OFFSET][s2.size() - 1 + OFFSET];
  }
};
