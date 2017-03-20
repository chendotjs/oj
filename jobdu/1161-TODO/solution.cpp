// POJ3768-Repeater
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int N; // the size of the template is N*N (N could only be 3, 4 or 5).
int Q;

char Template[10][10];
char Result[3002][3002];

void inputTemplate() {
  for (int i = 0; i < N; i++) {
    fgets(Template[i], 10, stdin); // fgets contains \n
  }

  for(int )
}

int main() {
  while (scanf("%d", &N) != EOF && N != 0) {
    getchar();
    inputTemplate();
    for (int i = 0; i < N; i++) {
      printf("lal %s\n", Template[i]);
    }

    scanf("%d", &Q);
  }
  return 0;
}
