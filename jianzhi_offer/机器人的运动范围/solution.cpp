#include <cstdio>
#include <cstring>

int go[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
class Solution {
public:
  int count;
#define N 1000
  bool visited[N][N];
  int row;
  int col;
  int k;

  int getDigitSum(int n) {
    int sum = 0;
    while (n != 0) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }
  void dfs(int x, int y) {
    int nx, ny;
    for (int i = 0; i < 4; i++) {
      nx = x + go[i][0];
      ny = y + go[i][1];
      if (nx < 0 || nx >= row || ny < 0 || ny >= col)
        continue;
      if (visited[nx][ny])
        continue;
      if (getDigitSum(nx) + getDigitSum(ny) > k)
        continue;
      count++;
      visited[nx][ny] = true;
      // printf("%d %d\n", nx, ny);
      dfs(nx, ny);
    }
  }
  int movingCount(int threshold, int rows, int cols) {
    count = 0;
    row = rows;
    col = cols;
    k = threshold;
    memset(visited, 0, sizeof(visited));
    visited[0][0] = true;
    if (k >= 0) count++;
    dfs(0, 0);
    return count;
  }
};

int main(int argc, char const *argv[]) {
  {
    Solution s;
    printf("%d\n", s.movingCount(2, 3, 2)); //5
  }

  {
    Solution s;
    printf("%d\n", s.movingCount(5, 3, 2)); //6
  }

  {
    Solution s;
    printf("%d\n", s.movingCount(18, 40, 50)); //6
  }
  return 0;
}
