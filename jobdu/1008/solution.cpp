#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct E {
  int next;
  int d;
  int p;
};

vector<E> edge[1001];
int dis[1001];
int cost[1001];
bool mark[1001];

int main() {
  int n, m, s, t;
  while (scanf("%d%d", &n, &m) != EOF && !(n == 0 && m == 0)) {
    for (int i = 0; i < 1001; i++) {
      edge[i].clear();
      mark[i] = false;
      dis[i] = -1;
      cost[i] = 0;
    }
    struct E e;
    while (m--) {
      int w, x, y, z;
      scanf("%d%d%d%d", &w, &x, &y, &z);
      e.next = x;
      e.d = y;
      e.p = z;
      edge[w].push_back(e);
      e.next = w;
      edge[x].push_back(e);
    }
    scanf("%d%d", &s, &t);
    // init
    for (int i = 0; i < edge[s].size(); i++) {
      dis[edge[s][i].next] = edge[s][i].d;
      cost[edge[s][i].next] = edge[s][i].p;
    }
    mark[s] = true;
    dis[s] = 0;
    cost[s] = 0;

    int prevp = s;
    int newp = -1;
    for (int i = 1; i < n; i++) {
      int min = 0x7fffffff;
      newp = -1;
      for (int j = 1; j <= n; j++) {
        if (dis[j] == -1 || mark[j] == true)
          continue;
        if (dis[j] < min) {
          min = dis[j];
          newp = j;
        }
      }
      //printf("%d->%d\n", prevp, newp);
      prevp = newp;
      mark[newp] = true;
      for (int j = 0; j < edge[newp].size(); j++) {
        int next = edge[newp][j].next;
        int d = edge[newp][j].d;
        int co = edge[newp][j].p;
        if (mark[next] == true)
          continue;
        if (dis[next] == -1 || dis[next] > d + dis[newp] ||
            (dis[next] == d + dis[newp] && cost[next] > co + cost[newp])) {
          dis[next] = d + dis[newp];
          cost[next] = co + cost[newp];
          //printf("%d - %d\n", co, cost[newp]);
        }
      }
    }
    printf("%d %d\n", dis[t], cost[t]);
  }
}
