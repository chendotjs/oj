#include <cstdio>
using namespace std;

#define LENGTH 110

int raw[LENGTH];
int forward[LENGTH];
int backward[LENGTH];
int N;

void forward_sol() {
  forward[1] = 1;
  for (int i = 2; i <= N; i++) {
    int Max = 1;
    for (int j = 1; j < i; j++) {
      int n;
      if (raw[i] > raw[j]) {
        n = forward[j] + 1;
      } else
        n = 1;
      Max = Max > n ? Max : n;
    }
    forward[i] = Max;
  }
}

void backward_sol() {
  backward[N] = 1;
  for (int i = N - 1; i >= 1; i--) {
    int Max = 1;
    for (int j = N; j > i; j--) {
      int n;
      if (raw[i] > raw[j]) {
        n = backward[j] + 1;
      } else
        n = 1;
      Max = Max > n ? Max : n;
    }
    backward[i] = Max;
  }
}

int main(int argc, char const *argv[]) {
  while (scanf("%d", &N) != EOF) {
    for (int i = 1; i <= N; i++) {
      scanf("%d", raw + i);
    }
    forward_sol();
    backward_sol();

    int ans = -1;
    int maxSum = -1;
    for (int i = 1; i <= N; i++) {
      if (forward[i] + backward[i] > maxSum)
        maxSum = forward[i] + backward[i];
    }
    ans = N - maxSum + 1;
    printf("%d\n", ans);
  }
  return 0;
}
