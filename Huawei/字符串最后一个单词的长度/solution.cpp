#include <cstdio>
#include <cstring>

char str[5010];

int main() {
  while (fgets(str, 5010, stdin) != NULL) {
    int len = strlen(str);
    str[len - 1] = '\0';
    len--;
    int wordlen = len;
    for (int i = len - 1; i >= 0; i--) {
      if (str[i] == ' ') {
        wordlen = len - i - 1;
        break;
      }
    }
    printf("%d\n", wordlen);
  }
}
