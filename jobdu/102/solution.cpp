// dp(i, j) = min | dp(i-1, j)
//                | dp(i-1, j-w[i]) + v[i]
//                | dp(i, j-w[i]) + v[i]


#include <cstdio>
#include <cstring>

using namespace std;

#define INF 0x7fffffff
struct E {
  int w;
  int v;
};

struct E list[501];

int min(int a, int b) { return a < b ? a : b; }

int dp[501][10001];

int main(int argc, char const *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int s, tmp;
    scanf("%d%d", &tmp, &s);
    s -= tmp;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &list[i].v, &list[i].w);
    }

    for (int i = 0; i <= s; i++) {
      dp[0][i] = INF;
    }
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= s; j++) {
        j = j;
        if (j - list[i].w < 0) {
          dp[i][j] = dp[i - 1][j];
        } else {
          int tmpmin = INF;
          if (dp[i - 1][j - list[i].w] == INF) {
            tmpmin = dp[i - 1][j];
          } else
            tmpmin = min(dp[i - 1][j], dp[i - 1][j - list[i].w] + list[i].v);
          if (dp[i][j - list[i].w] == INF)
            dp[i][j] = tmpmin;
          else
            dp[i][j] = min(dp[i][j - list[i].w] + list[i].v, tmpmin);
        }
      }
    }
    if (dp[n][s] != INF)
      printf("The minimum amount of money in the piggy-bank is %d.\n", dp[n][s]);
    else
      puts("This is impossible.");
  }
  return 0;
}
