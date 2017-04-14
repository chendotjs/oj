#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  int A, B ,K;
  while (scanf("%d%d%d", &A, &B, &K) != EOF && !(A == 0 && B == 0)) {
    int base = 1;
    while (K--) {
      base *= 10;
    }
    int result;
    if (A % base == B % base) {
      result  =  -1;
    } else {
      result = A + B;
    }
    printf("%d\n", result);
  }
  return 0;
}
