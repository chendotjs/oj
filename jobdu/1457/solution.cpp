#include <cstdio>
#include <queue>
using namespace std;

struct N {
  int a, b, c;
  int t;
};

#define LENGTH 101
int mark[LENGTH][LENGTH][LENGTH];

queue<struct N> Q;

void AtoB(int &a, int sa, int &b, int sb) {
  if (a <= sb - b) { // b not full
    b += a;
    a = 0;
  } else { // b full
    a -= (sb - b);
    b = sb;
  }
}

bool average(int a, int b, int c, int s) {
  if (a == s / 2 && b == s / 2)
    return true;
  if (a == s / 2 && c == s / 2)
    return true;
  if (c == s / 2 && b == s / 2)
    return true;
  return false;
}

int BFS(int s, int m, int n) {
  int a, b, c, t;
  while (Q.empty() == false) {
    struct N now = Q.front();
    Q.pop();

    // a->b
    a = now.a;
    b = now.b;
    c = now.c;
    t = now.t;
    AtoB(a, s, b, m);
    if (mark[a][b][c] == 0) {
      mark[a][b][c] = 1;
#ifdef DEBUG
      printf("a->b %d %d %d %d | %d %d %d %d\n", now.a, now.b, now.c, now.t, a, b,
             c, t);
#endif
      struct N tmp = {a, b, c, t + 1};
      if (average(a, b, c, s))
        return t + 1;
      Q.push(tmp);
    }

    // b->a
    a = now.a;
    b = now.b;
    c = now.c;
    t = now.t;
    AtoB(b, m, a, s);
    if (mark[a][b][c] == 0) {
      mark[a][b][c] = 1;
#ifdef DEBUG
      printf("b->a %d %d %d %d | %d %d %d %d\n", now.a, now.b, now.c, now.t, a, b,
             c, t);
#endif
      struct N tmp = {a, b, c, t + 1};
      if (average(a, b, c, s))
        return t + 1;
      Q.push(tmp);
    }

    // a->c
    a = now.a;
    b = now.b;
    c = now.c;
    t = now.t;
    AtoB(a, s, c, n);
    if (mark[a][b][c] == 0) {
      mark[a][b][c] = 1;
#ifdef DEBUG
      printf("a->c %d %d %d %d | %d %d %d %d\n", now.a, now.b, now.c, now.t, a, b,
             c, t);
#endif
      struct N tmp = {a, b, c, t + 1};
      if (average(a, b, c, s))
        return t + 1;
      Q.push(tmp);
    }

    // c->a
    a = now.a;
    b = now.b;
    c = now.c;
    t = now.t;
    AtoB(c, n, a, s);
    if (mark[a][b][c] == 0) {
      mark[a][b][c] = 1;
#ifdef DEBUG
      printf("c->a %d %d %d %d | %d %d %d %d\n", now.a, now.b, now.c, now.t, a, b,
             c, t);
#endif
      struct N tmp = {a, b, c, t + 1};
      if (average(a, b, c, s))
        return t + 1;
      Q.push(tmp);
    }

    // b->c
    a = now.a;
    b = now.b;
    c = now.c;
    t = now.t;
    AtoB(b, m, c, n);
    if (mark[a][b][c] == 0) {
      mark[a][b][c] = 1;
#ifdef DEBUG
      printf("b->c %d %d %d %d | %d %d %d %d\n", now.a, now.b, now.c, now.t, a, b,
             c, t);
#endif
      struct N tmp = {a, b, c, t + 1};
      if (average(a, b, c, s))
        return t + 1;
      Q.push(tmp);
    }

    // c->b
    a = now.a;
    b = now.b;
    c = now.c;
    t = now.t;
    AtoB(c, n, b, m);
    if (mark[a][b][c] == 0) {
      mark[a][b][c] = 1;
#ifdef DEBUG
      printf("c->b %d %d %d %d | %d %d %d %d\n", now.a, now.b, now.c, now.t, a, b,
             c, t);
#endif
      struct N tmp = {a, b, c, t + 1};
      if (average(a, b, c, s))
        return t + 1;
      Q.push(tmp);
    }
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  int s, n, m;
  while (scanf("%d%d%d", &s, &m, &n) != EOF && s != 0) {
    while (Q.empty() == false)
      Q.pop();

    if (s & 0x01 == 1) {
      printf("NO\n");
      continue;
    }

    for (int i = 0; i <= s; i++) {
      for (int j = 0; j <= m; j++) {
        for (int k = 0; k <= n; k++) {
          mark[i][j][k] = 0;
        }
      }
    }
    struct N tmp = {s, 0, 0, 0};
    Q.push(tmp);
    mark[0][0][0] = 1;

    int ret = BFS(s, m, n);
    if (ret != -1)
      printf("%d\n", ret);
    else
      printf("NO\n");
  }
  return 0;
}
