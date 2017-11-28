#include <cstdio>
#include <iostream>

using namespace std;

int k;
int arr[30];
int dp[30];

int solution() {
  dp[1] = 1;
  for (int i = 2; i <= k; i++) {
    int Max = -1;
    for (int j = 1; j < i; j++) {
      int n;
      if (arr[i] <= arr[j]) {
        n = dp[j] + 1;
      } else
        n = 1;
      Max = n > Max ? n : Max;
    }
    dp[i] = Max;
  }
  int ans = dp[1];
  for (int i = 1; i <= k; i++) {
    if (dp[i] > ans)
      ans = dp[i];
  }
  return ans;
}

int main() {
  while (scanf("%d", &k) != EOF) {
    for (int i = 1; i <= k; i++) {
      scanf("%d", &arr[i]);
    }
    printf("%d\n", solution());
  }
  return 0;
}
