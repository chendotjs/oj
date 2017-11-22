#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char input[10];
int length;
bool mark[10];
char output[10];

void DFS(int depth) {
  if (depth == length) {
    printf("%s\n", output);
    return;
  }
  for (int i = 0; i < length; i++) {
    if (mark[i] == false) {
      mark[i] = true;
      output[depth] = input[i];
      DFS(depth + 1);
      mark[i] = false;
    }
  }
}

int main(int argc, char const *argv[]) {
  while (scanf("%s", input) != EOF) {
    length = strlen(input);
    std::sort(input, input + length);
    memset(mark, 0 , sizeof(mark));
    DFS(0);
    printf("\n");
  }
  return 0;
}
