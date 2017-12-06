#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define LENGTH 10001

int prime[LENGTH];
int mark[LENGTH];
int pcnt = 0;

void init() {
  memset(mark, 0, sizeof(mark));
  for (long int i = 2; i < LENGTH; i++) {
    if (mark[i] == 1) continue;
    for (long int j = i * i; j>=0 && j < LENGTH; j += i) {
      mark[j] = 1;
    }
  }
  for (long int i = 2; i < LENGTH; i++) {
    if (mark[i] == 0) {
      //printf("%d\n", i);
      prime[pcnt++] = i;
    }
  }
}

int main() {
  init();
  long int M;
  while (scanf("%ld", &M) != EOF) {
    for (int i = 0; i < pcnt; i++) {
      while (M % prime[i] == 0) {
        printf("%d ", prime[i]);
        M /= prime[i];
      }
    }
    if (M != 1) {
      printf("%d ", M);
    }
  }
  return 0;
}

