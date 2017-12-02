#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define LENGTH 2003

int item[LENGTH];
int dp[LENGTH][LENGTH / 2 + 1];

int n, k;

void solution() {
   for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
   }
  //dp[2][1] = (item[1] - item[2]) * (item[1] - item[2]);
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j * 2 == i) {
        dp[i][j] = dp[i - 2][j - 1] + (item[i - 1] - item[i]) * (item[i - 1] - item[i]);
      } else if (j * 2 < i) {
        int n1 = dp[i - 2][j - 1] + (item[i - 1] - item[i]) * (item[i - 1] - item[i]);
        int n2 = dp[i - 1][j];
        dp[i][j] = n1 < n2 ? n1 : n2;
      }
      //printf("dp[%d][%d]: %d\n", i, j, dp[i][j]);
    }
  }
  printf("%d\n", dp[n][k]);
}

int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", item + i);
    }

    sort(item + 1, item + 1 + n);
    solution();
  }
  return 0;
}

