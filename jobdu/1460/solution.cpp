#include <cstdio>
#include <cstring>

using namespace std;

#define LENGTH 102

char maze[LENGTH][LENGTH];
bool mark[LENGTH][LENGTH];
int ans;
int n, m;

int go[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1},
               {1, -1},  {1, 0},  {1, 1}
};

void DFS(int x, int y) {
  int nx, ny;
  for (int i = 0; i < 8; i++) {
    nx = go[i][0] + x;
    ny = go[i][1] + y;
    if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
    if (maze[nx][ny] == '*' || mark[nx][ny] == true) continue;
    mark[nx][ny] = true;
    // printf("-%d %d\n", nx, ny);
    DFS(nx, ny);
  }
  return;
}

int main() {
  while (scanf("%d%d", &n, &m) != EOF && !(n == 0 && m == 0)) {

    for (int i = 1; i <= n; i++) {
      scanf("%s", maze[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        mark[i][j] = false;
      }
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (maze[i][j] == '@' && mark[i][j] == false) {
          ans++;
          // printf("%d %d\n", i, j);
          DFS(i, j);
        } else
          continue;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
