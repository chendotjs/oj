#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int n;
typedef struct program {
  int start;
  int end;
} program;

bool cmp(const program &p1, const program &p2) { return p1.end < p2.end; }

program p[200];

int main() {
  while (scanf("%d", &n) && n != 0) {
    int count = 0;
    int maxStart = -1;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &p[i].start, &p[i].end);
      if (p[i].start > maxStart)
        maxStart = p[i].start;
    }
    sort(p, p + n, cmp);
    int current = 0;
    // program previous = p[current];
    while (p[current].end <= maxStart) {
      for (int i = current + 1; i < n; i++) {
        if (p[i].start >= p[current].end) {
          count++;
          current = i;
          // printf("-- %d %d\n", p[i].start, p[i].end); 
        }
      }
    }
    printf("%d\n", count + 1);
  }
  return 0;
}
