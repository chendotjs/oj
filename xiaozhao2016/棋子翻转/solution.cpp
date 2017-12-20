#include <iostream>
#include <vector>
using namespace std;

int go[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Flip {
public:
    #define OFFSET (-1)
    vector<vector<int> > flipChess(vector<vector<int> > A, vector<vector<int> > f) {
        // write code here
      for (int i = 0; i < f.size(); i++) {
        int x = f[i][0] + OFFSET;
        int y = f[i][1] + OFFSET;
        for (int j = 0; j < 4; j++) {
          int nx = x + go[j][0];
          int ny = y + go[j][1];
          if (nx >=0 && nx <=3 && ny >=0 && ny <=3) {
            A[nx][ny] = 1 - A[nx][ny];
          }
        }

      }
      return A;
    }
};

int main() {
  {
    Flip s;
    vector<vector<int> > A = {{0,0,1,1}, {1,0,1,0}, {0,1,1,0}, {0,0,1,0}};
    vector<vector<int> > f = {{2, 2}, {3, 3}, {4, 4}};
    vector<vector<int> > ans = s.flipChess(A, f);
    ans = ans;
  }
  return 0;
}

