/*
此题除了要满足例子以外，还要满足一些条件才能真正算ac：
0 1
1 0
1.000

1 0
0.000
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef struct Room {
  double J;
  double F;
  double rate;
} Room;

Room room[1003];

bool cmp(const Room &h1, const Room &h2) { return h1.rate > h2.rate; }
int M, N;

int main() {

  while (scanf("%d%d", &M, &N)) {
    if (M == -1 && N == -1)
      return 0;
    for (int i = 0; i < N; i++) {
      scanf("%lf", &(room[i].J));
      scanf("%lf", &(room[i].F));
      room[i].rate = (room[i].J + 0.0) / room[i].F;
    }
    std::sort(room, room + N, cmp);
    double Jsum = 0;
    double Fsum = 0;
    int currentRoom = 0;
    while (Fsum < (M + 0.0001) && currentRoom < N && room[currentRoom].J > 0) {
      if ((M - Fsum) > room[currentRoom].F || abs(M - Fsum) < 0.0001) {
        Jsum += room[currentRoom].J;
        room[currentRoom].J = 0;
        Fsum += room[currentRoom].F;
        currentRoom++;
      } else {
        Jsum += room[currentRoom].rate * (M - Fsum);
        Fsum = M;
        break;
      }
    }
    printf("%.3lf\n", Jsum);
  }
  return 0;
}
