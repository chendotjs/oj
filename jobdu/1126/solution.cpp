#include <cstdio>
#include <iostream>
using namespace std;

int a[10000];


void extreme(int num) {
  bool flag = false;
  for (int i = 0; i < num; i++) {
    int f = a[i] - a[i - 1];
    int b = a[i] - a[i + 1];
    if (i - 1 >= 0 && i + 1 < num) {
      if (f * b > 0) {
        if (flag)
          printf(" %d", i);
        else {
          printf("%d", i);
          flag = true;
        }
      }
    } else if (i == 0 && a[i] != a[i + 1]) {
      printf("%d", i);
      flag = true;
    } else if (i == num - 1 && a[i] != a[i - 1]) {
      printf(" %d", i);
    }
  }
  printf("\n");
}

int main() {
  int count, num;
  scanf("%d", &count);
  while (count--) {
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
      scanf("%d", a + i);
    extreme(num);
  }
  return 0;
}
