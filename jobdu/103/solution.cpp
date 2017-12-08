#include <cstdio>

struct E {
  int w;
  int v;
};

struct E list[110];
int dp[110];

int max(int a, int b) { return a > b ? a : b; }

int main(int argc, char const *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int s, n;
    scanf("%d%d", &s, &n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      int v, w, k;
      scanf("%d%d%d", &w, &v, &k);
      int c = 1;
      while (k - c > 0) {
        k -= c;
        list[++cnt].w = w * c;
        list[cnt].v = c * v;
        c *= 2;
      }
      list[++cnt].w = w * k;
      list[cnt].v = k * v;
    }
    for (int i = 1; i <= s; i++)
      dp[i] = 0;                     //初始值
    for (int i = 1; i <= cnt; i++) { //对拆分后的所有物品进行0-1背包
      for (int j = s; j >= list[i].w; j--) {
        dp[j] = max(dp[j], dp[j - list[i].w] + list[i].v);
      }
    }
    printf("%d\n", dp[s]); //输出答案
  }
  return 0;
}
