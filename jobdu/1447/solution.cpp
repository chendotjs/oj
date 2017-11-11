#include <cstdio>
#include <cstring>

using namespace std;

int rect[101][101];
int N, M;

void initRect(int n) {
  for (int i = 0; i < n + 1; i++)
    for (int j = 0; j < n + 1; j++) {
      if (i == j)
        rect[i][j] = 0;
      else
        rect[i][j] = -1;
    }

}


void floyd() {
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (rect[i][k] == -1 || rect[k][j] == -1)
          continue;
        if (rect[i][j] == -1 || rect[i][k] + rect[k][j] < rect[i][j])
          rect[i][j] = rect[i][k] + rect[k][j];
      }
    }
  }
}

int main() {
  while (scanf("%d%d", &N, &M) != EOF && !(N == 0 && M == 0)) {
    initRect(N);
    while (M--) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      rect[a][b] = rect[b][a] = c;
    }
    floyd();
    printf("%d\n", rect[1][N]);
  }
  return 0;
}


