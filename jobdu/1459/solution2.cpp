#include <cstdio>
#include <cstring>
using namespace std;

int ans[22];
bool hash[22];

int prime[40];
int pmark[40];
int pcnt;
int n;

void initprime() {
  memset(pmark, 0, sizeof(pmark));
  pcnt = 0;

  for (int i = 2; i < 40; i++) {
    if (pmark[i] == 0) {
      for (int j = i * i; j < 40; j += i) {
        pmark[j] = 1;
      }
    }
  }
  for (int i = 2; i < 40; i++) {
    if (pmark[i] == 0) { // mark 0 is prime
      prime[pcnt++] = i;
      // printf("%d \n", i);
    }
  }
}

bool judge(int x) {
  if (pmark[x] == 0)
    return true;
  return false;
}

void check() {
  if (judge(ans[1] + ans[n]) == false)
    return;
  for (int i = 1; i <= n; i++) {
    if (i != 1)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
}

void DFS(int num) {
  if (num > 1) {
    int sum = ans[num] + ans[num - 1];
    if (judge(sum) == false)
      return;
  }
  if (num == n) {
    check();
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (hash[i] == false) {
      hash[i] = true;
      ans[num + 1] = i;
      DFS(num + 1);
      hash[i] = false;
    }
  }
}

int caseid = 1;
int main(int argc, char const *argv[]) {
  initprime();
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i <= n; i++) {
      hash[i] = false;
    }
    ans[1] = 1;
    hash[1] = true;
    printf("Case %d:\n", caseid++);
    DFS(1);
    printf("\n");
  }

  return 0;
}
