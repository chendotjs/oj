#include <cstdio>

using namespace std;

int countbit(int N) {
  int base = 1;
  while(N > 0) {
    base *= 10;
    N /= 10;
  }
  return base;
}

int main() {
  int N;
  while (scanf("%d", &N) != EOF) {
    int base  = countbit(N);
    int result = (N % base) * (N % base);
    result = result % base;
    if (result == N) {
      printf("Yes!\n");
    } else {
      printf("No!\n");
    }
  }
  return 0;
}
