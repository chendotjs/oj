/**
        B(n - 1)        B(n - 1)
B(n) ->         B(n - 1)
        B(n - 1)        B(n - 1)

http://blog.csdn.net/hackbuteer1/article/details/7321602
*/

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char array[800][800];

void dfs(int depth, int x, int y) {
  if (depth == 1) {
    array[x][y] = 'X';
    return;
  }
  int currentSize = pow(3, depth - 2);

  dfs(depth - 1, x, y);
  dfs(depth - 1, x, y + 2 * currentSize);
  dfs(depth - 1, x + currentSize, y + currentSize);
  dfs(depth - 1, x + 2 * currentSize, y);
  dfs(depth - 1, x + 2 * currentSize, y + 2 * currentSize);
}

int main() {
  int degree;
  while (scanf("%d", &degree) && degree != -1) {
    memset(array, ' ', sizeof(array));
    dfs(degree, 0, 0);
    int size = pow(3, degree - 1);
    for (int i = 0; i < size; i++) {
      array[i][size] = '\0';
      puts(array[i]);
    }
    putchar('-');
    putchar('\n');
  }
  return 0;
}
