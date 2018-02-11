#include <cstdio>
#include <iostream>

using namespace std;

#define LENGTH 10000
int N;
int mates[LENGTH];
int forward_mate[LENGTH];
int backward_mate[LENGTH];

int main(int argc, char const *argv[]) {
  // freopen("case.txt", "r", stdin);
  while (scanf("%d", &N) != EOF) {
    for (int i = 0; i < N; i++) {
      scanf("%d", mates + i);
    }

    forward_mate[0] = 1;
    for (int i = 1; i < N; i++) {
      int m = 0;
      for (int j = 0; j < i; j++) {
        if (mates[i] > mates[j]) {
          m = m > forward_mate[j] ? m : forward_mate[j];
        }
      }
      forward_mate[i] = m + 1;
    }

    backward_mate[N - 1] = 1;
    for (int i = N - 2; i >= 0; i--) {
      int m = 0;
      for (int j = N - 1; j > i; j--) {
        if (mates[i] > mates[j]) {
          m = m > backward_mate[j] ? m : backward_mate[j];
        }
        backward_mate[i] = m + 1;
      }
    }

    int m = -1;
    for (int i = 0; i < N; i++) {
      int sum = forward_mate[i] + backward_mate[i];
      m = sum > m ? sum : m;
    }
    printf("%d\n", N - (m - 1));
  }
  return 0;
}
