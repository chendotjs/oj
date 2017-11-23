#include <cstdio>
#include <cstring>
using namespace std;

char maze[8][8];
int n, m, T;
int sx, sy;
int ex, ey;
bool ans = false;

int go[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void DFS(int x, int y, int t) {
  // printf("--- %d %d %d\n", x, y, t);
  int nx, ny, nt;

  for (int i = 0; i < 4; i++) {
    nx = x + go[i][0];
    ny = y + go[i][1];
    nt = t + 1;
    if (nx == ex && ny == ey && nt == T) {
      ans = true;
      return;
    }
    if (nx < 1 || nx > n || ny < 1 || ny > m)
      continue;
    if (maze[nx][ny] == 'X')
      continue;
    maze[nx][ny] = 'X';
    DFS(nx, ny, nt);
    maze[nx][ny] = '.';
    if (ans) return;
  }
}

int main(int argc, char const *argv[]) {
  while (scanf("%d%d%d", &n, &m, &T) != EOF && T != 0) {
    ans = false;
    for (int i = 1; i <= n; i++) {
      scanf("%s", maze[i] + 1);
      for (int j = 1; j <= m; j++) {
        if (maze[i][j] == 'S') {
          sx = i;
          sy = j;
          // printf("%d %d\n", sx, sy);
        }
        if (maze[i][j] == 'D') {
          ex = i;
          ey = j;
          // printf("%d %d\n", ex, ey);
        }
      }
    }
    if (T % 2 != ((sx + sy) % 2 + (ex + ey) % 2) % 2) {
      printf("NO\n");
      continue;
    }
    maze[sx][sy] = 'X';
    DFS(sx, sy, 0);
    if (ans)
      puts("YES");
    else
      puts("NO");

  }
  return 0;
}
