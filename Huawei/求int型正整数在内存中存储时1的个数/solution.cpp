#include <iostream>

using namespace std;

int main() {
  int M;
  while (cin >> M) {
    int cnt = 0;
    while (M != 0) {
      if (M & 0x01 == 1) {
        cnt++;
      }
      M = M >> 1;
    }
    cout << cnt << endl;
  }
  return 0;
}

