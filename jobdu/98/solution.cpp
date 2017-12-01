#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[110][110];
char str1[110];
char str2[110];

#define max(a, b) (a > b ? a : b)


int main() {
  while (scanf("%s%s", str1 + 1, str2 + 1) != EOF) {
    int len1 = strlen(str1 + 1);
    int len2 = strlen(str2 + 1);

    for (int i = 0; i <= len1; i++)
      dp[i][0] = 0;
    for (int i = 0; i <= len2; i++)
      dp[0][i] = 0;

    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (str1[i] == str2[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    printf("%d\n", dp[len1][len2]);
  }

  return 0;
}

