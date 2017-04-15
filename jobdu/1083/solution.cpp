#include <iostream>
#include <cstdio>


int AC[200];
int sizeA;
int BC[200];
int sizeB;

int main() {
  int A, B;
  while (scanf("%d%d", &A, &B) != EOF) {
    sizeA = sizeB = 0;
    while (A > 0) {
      AC[sizeA++] = A % 10;
      A /= 10;
    }

    while (B > 0) {
      BC[sizeB++] = B % 10;
      B /= 10;
    }

    for (int i = 0; i < sizeA; i++) {
      A += AC[i];
    }

    for (int i = 0; i < sizeB; i++) {
      B += BC[i];
    }
    long long int ans = A * B;
    printf("%lld\n", ans);
  }
}
