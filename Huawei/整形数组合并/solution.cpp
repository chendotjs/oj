#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
vector<int> V;
int main(int argc, char const *argv[]) {
  while(scanf("%d", &n) != EOF) {
    int t;
    V.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d", &t);
      V.push_back(t);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      scanf("%d", &t);
      V.push_back(t);
    }
    std::sort(V.begin(), V.end());

    printf("%d", V[0]);
    for (int i = 1; i < m + n; i++) {
      if (V[i] != V[i - 1]) {
        printf("%d", V[i]);
      }
    }
  }
  return 0;
}
