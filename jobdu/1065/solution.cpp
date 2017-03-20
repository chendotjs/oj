#include <stdio.h>
void printLine(int blank, int star) {
  while (blank--)
    printf("%c", ' ');
  while (star--)
    printf("%c", '*');
  printf("\n");
}

int main() {
  int h;
  while (scanf("%d", &h) != EOF) {
    int blank = (h - 1) * 2;
    int star = h;
    int i;
    for (i = 1; i <= h; i++) {
      printLine(blank, star);
      blank -= 2;
      star += 2;
    }
  }
}
