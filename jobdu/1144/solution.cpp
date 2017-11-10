#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define LENGTH 5000

struct Point {
  double x;
  double y;
  double distance(const struct Point &p) {
    double xx = (x - p.x) * (x - p.x);
    double yy = (y - p.y) * (y - p.y);
    return sqrt(xx + yy);
  }
};

struct Edge {
  int a;
  int b;
  double cost;
  bool operator<(const struct Edge &e) { return cost <= e.cost; }
};

struct Point point[110];
struct Edge edge[LENGTH];

int root[110];

int findRoot(int x) {
  int ret;
  int tmp = x;
  while (x != root[x])
    x = root[x];
  ret = x;
  x = tmp;
  while (x != root[x]) {
    int y = root[x];
    root[x] = ret;
    x = root[x];
  }
  return ret;
}
int N;

int main() {
  while (scanf("%d", &N) != EOF) {
    for (int i = 1; i <= N; i++) {
      scanf("%lf%lf", &(point[i].x), &(point[i].y));
    }
    int L = N * (N - 1) / 2;

    for (int i = 1, cnt = 0; i <= N; i++) {
      for (int j = i + 1; j <= N; j++) {
        edge[cnt].a = i;
        edge[cnt].b = j;
        edge[cnt++].cost = point[i].distance(point[j]);
      }
    }

    std::sort(edge, edge + L);
    for (int i = 0; i < 110; i++)
      root[i] = i;

    double ans = 0;
    for (int i = 0; i < L; i++) {
      int ra = findRoot(edge[i].a);
      int rb = findRoot(edge[i].b);
      if (ra != rb) {
        root[ra] = rb;
        ans += edge[i].cost;
      }
    }

    printf("%.2lf\n", ans);
  }
  return 0;
}
