#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct E {
  int next;
  int c;
};

vector<E> edge[101];
bool mark[101];
int dis[101];

void init() {
  for (int i = 0; i < 101; i++) {
    edge[i].clear();
    mark[i] = 0;
  }
}

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF && !(n == 0 && m == 0)) {
    init();
    while (m--) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      struct E e;
      e.next = b;
      e.c = c;
      edge[a].push_back(e);
      e.next = a;
      edge[b].push_back(e);
    }


    for (int i = 1; i <= n; i++)
      dis[i] = -1;
    for (int i = 0; i < edge[1].size(); i++) {
      dis[edge[1][i].next] = edge[1][i].c;
    }
    dis[1] = 0;
    mark[1] = true;
    for (int i = 1; i < n; i++) {
      int min = 123123123;
      int newP;
      for (int j = 1; j <= n; j++) {
        if (dis[j] == -1 || mark[j] == true) continue;
        if (dis[j] < min && mark[j] == false) {
          newP = j;
          min = dis[j];
        }
      }
      mark[newP] = true;
      // printf("%d\n", newP);

      for (int j = 0; j < edge[newP].size(); j++) {
        int t = edge[newP][j].next;
        int c = edge[newP][j].c;
        if (dis[t] == -1 || dis[newP] + c < dis[t]) {
          dis[t] = dis[newP] + c;
        }
      }
    }
    printf("%d\n", dis[n]);
  }

  return 0;
}


