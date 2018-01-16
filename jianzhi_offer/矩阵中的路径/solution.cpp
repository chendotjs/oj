#include <cstdio>
#include <cstring>
using namespace std;

int go[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

class Solution {
public:
#define N 1000
  bool visited[N][N];
  char m[N][N];
  int len;
  int row;
  int col;
  bool success;
  bool hasPath(char *matrix, int rows, int cols, char *str) {
    memset(visited, 0, sizeof(visited));
    for (int i = 0, idx = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        m[i][j] = matrix[idx++];
      }
    }
    len = strlen(str);
    row = rows;
    col = cols;
    success = false;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (str[0] == m[i][j]) {
          if (len == 1) return true;
          visited[i][j] = true;
          dfs(i, j, 1, str);
          visited[i][j] = false;
        }
      }
    }
    return success;
  }

  void dfs(int x, int y, int t, char *str) {
    for (int i = 0; i < 4; i++) {
      int nx = x + go[i][0];
      int ny = y + go[i][1];
      if (nx < 0 || nx >= row || ny < 0 || ny >= col)
        continue;
      if (visited[nx][ny])
        continue;
      // printf("%d %d %c\n", nx, ny, m[nx][ny]);

      if (m[nx][ny] == str[t] && t == len - 1) {
        success = true;
      } else if (m[nx][ny] == str[t]) {
        visited[nx][ny] = true;
        dfs(nx, ny, t + 1, str);
        visited[nx][ny] = false;
      } else if (m[nx][ny] != str[t]) {
        continue;
      }
    }
    if (success)
      return;
  }
};

int main(int argc, char const *argv[]) {
  {
    char matrix[] = {'a', 'b', 't', 'g', 'c', 'f',
                     'c', 's', 'j', 'd', 'e', 'h'};
    Solution s;
    printf("%d\n", s.hasPath(matrix, 3, 4, "bfce"));
  }

  {
    char matrix[] = {'a', 'b', 't', 'g', 'c', 'f',
                     'c', 's', 'j', 'd', 'e', 'h'};
    Solution s;
    printf("%d\n", s.hasPath(matrix, 3, 4, "abfb"));
  }

  {
    char matrix[] = {'a', 'b', 't', 'g', 'c', 'f',
                     'c', 's', 'j', 'd', 'e', 'h'};
    Solution s;
    printf("%d\n", s.hasPath(matrix, 3, 4, "ce"));
  }

  {
    char matrix[] = {'a', 'b', 't', 'g', 'c', 'f',
                     'c', 's', 'j', 'd', 'e', 'h'};
    Solution s;
    printf("%d\n", s.hasPath(matrix, 3, 4, "cg"));
  }

  {
    char matrix[] = {'a', 'b', 't', 'g', 'c', 'f',
                     'c', 's', 'j', 'd', 'e', 'h'};
    Solution s;
    printf("%d\n", s.hasPath(matrix, 3, 4, "z"));
  }

  {
    char matrix[] = {'A'};
    Solution s;
    printf("%d\n", s.hasPath(matrix, 1, 1, "A"));
  }

  return 0;
}
