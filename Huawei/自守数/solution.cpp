#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int automorphic[1001];
int pauto = 0;
void init() {
  for (long int i = 0; i < 20000; i++) {
    long pow2 = i * i;
    long int t = 1;
    while (t <= i)
      t *= 10;
    if (pow2 % t == i) {
      //printf("%ld\n", i);
      automorphic[pauto++] = i;
    }
  }
}

int main() {
  int M;
  init();
  while (scanf("%d", &M) != EOF) {
    int cnt = 0;
    for (int i = 0; i < pauto; i++) {
      if (automorphic[i] < M) {
        cnt++;
      } else break;
    }
    printf("%d\n", cnt);
  }
  return 0;
}

