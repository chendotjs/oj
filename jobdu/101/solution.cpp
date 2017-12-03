#include <iostream>
#include <cstdio>

using namespace std;

int T;
int M;

int dp[101][1001];
int ttime[101];
int value[101];

int main() {
  while (scanf("%d", &T) != EOF) {
    scanf("%d", &M);
    for (int i = 1; i <= M; i++) {
      scanf("%d%d", ttime + i, value + i);
    }

    for (int i = 0; i <= T; i++) {
      dp[0][i] = 0;
    }

    for (int i = 1; i <= M; i++) {
      for (int j = 0; j <= T; j++) {
        // max
        int tt = j - ttime[i];
        if (tt < 0) {
          dp[i][j] = dp[i - 1][j];
        } else {
          int tmp1 = dp[i - 1][tt] + value[i];
          int tmp2 = dp[i - 1][j];
          if (tmp1 < tmp2)
            tmp1 = tmp2;
          dp[i][j] = tmp1;
        }
      }
    }
    printf("%d\n", dp[M][T]);
  }
  return 0;
}

