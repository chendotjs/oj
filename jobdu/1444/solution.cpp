#include <cstdio>
#include <cstring>

using namespace std;

#define LENGTH 10000001

int root[LENGTH];
int cnt[LENGTH];

int N;

int findRoot(int x) {
  int ret;
  int tmp = x;
  while (root[x] != x) {
    x = root[x];
  }
  ret = x;
  int y;
  x = tmp;
  while (root[x] != x) {
    y = root[x];
    root[x] = ret;
    x = y;
  }
  return ret;
}

int main() {
  while (scanf("%d", &N) != EOF) {
    // init
    for (int i = 0; i < LENGTH; i++) {
      cnt[i] = 1;
      root[i] = i;
    }

    // input
    int a, b;
    int M = N;
    int ra, rb;
    int max = 1;
    while (M--) {
      scanf("%d%d", &a, &b);
      ra = findRoot(a);
      rb = findRoot(b);
      if (ra != rb) {
        root[ra] = rb;
        cnt[rb] += cnt[ra];
        if (cnt[rb] > max) {
          max = cnt[rb];
          // printf("%d-%d\n", rb, cnt[rb]);
        }
      }
    }

    printf("%d\n", max);
  }
  return 0;
}
