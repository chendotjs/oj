#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[BUFSIZ];

int main() {
  while (fgets(str, BUFSIZ, stdin) != NULL) {
    int len = strlen(str);
    len--;
    str[len] = '\0';

    char match;
    match = getchar();
    getchar();
    int cnt = 0;
    for (int i = len - 1; i >= 0; i--) {
      if (str[i] == match || str[i] - match == 'A' - 'a' ||  str[i] - match == 'a' - 'A')
        cnt++;
    }
    printf("%d\n", cnt);
  }
  return 0;
}

