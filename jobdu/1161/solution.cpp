// POJ3768-Repeater
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int N; // the size of the template is N*N (N could only be 3, 4 or 5).
int Q;
char CHAR = ' ';

char Template[10][10];
char Result[3002][3002];

void inputTemplate() {
  for (int i = 0; i < N; i++) {
    fgets(Template[i], 10, stdin); // fgets contains \n
  }
  // scan
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (Template[i][j] != ' ' && Template[i][j] != '\n') {
        CHAR = Template[i][j];
        break;
      }
    }
    if (CHAR != ' ')
      break;
  }
}

void dfs(int depth, int x, int y) {
  if (depth == 0) {
    Result[x][y] = CHAR;
    return;
  }

  int size = pow(N, depth - 1);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (Template[i][j] == CHAR) {
        // printf("%d %d\n", i, j);
        dfs(depth - 1, x + i * size, y + j * size);
      }
    }
  }
}

int main() {
  while (scanf("%d", &N) != EOF && N != 0) {
    getchar();
    memset(Result, ' ', sizeof(Result));
    inputTemplate();

    scanf("%d", &Q);

    dfs(Q, 0, 0);
    int size = pow(N, Q);

    for (int i = 0; i < size; i++) {
      Result[i][size] = '\0';
      puts(Result[i]);
    }
  }
  return 0;
}
