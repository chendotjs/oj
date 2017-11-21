#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int prime[40];
int pmark[40];
int pcnt;

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

#define LENGTH 18

struct N {
  int A[LENGTH];
  bool mark[LENGTH];
  int t;
  int l;
};

queue<struct N> Q;

bool prune(struct N &node) {
  for (int i = 1; i <= node.t - 1; i++) {
    int sum = node.A[i] + node.A[i + 1];
    if (pmark[sum] == 1)
      return false;
  }
  if (node.t == node.l) {
    int sum = node.A[1] + node.A[node.t];
    if (pmark[sum] == 1)
      return false;
  }
  return true;
}

void BFS() {
  int l, t;
  while (Q.empty() == false) {
    struct N now = Q.front();
    Q.pop();
    l = now.l;
    t = now.t + 1;

    for (int i = 1; i <= l; i++) {
      struct N tmp = now;
      tmp.t = t;
      if (tmp.mark[i] == 0) {
        tmp.A[t] = i;
        tmp.mark[i] = 1;
        // judge prime
        if (prune(tmp) == false)
          continue;

        if (tmp.t == l) {
          for (int j = 1; j <= l; j++) {
            if (j != 1)
              printf(" ");
            printf("%d", tmp.A[j]);
          }
          printf("\n");
        }
        Q.push(tmp);
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  initprime();
  int n;
  int caseid = 1;
  while (scanf("%d", &n) != EOF) {
    while (Q.empty() == false)
      Q.pop();
    struct N first;
    memset(&first, 0, sizeof(first));
    first.t = 1;
    first.l = n;
    first.mark[1] = 1;
    first.A[1] = 1;
    Q.push(first);
    printf("Case %d:\n", caseid++);
    BFS();
    printf("\n");
  }
  return 0;
}
