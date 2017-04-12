#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
// #define debug

class Solution {
public:
  /**
   * @param grid a boolean 2D matrix
   * @return an integer
   */
  int numIslands(vector<vector<bool>> &grid) {
    // Write your code here
    int x = grid.size();
    sizex = x;
    if (x == 0)
      return 0;
    int y = grid[0].size();
    sizey = y;

    for (vector<vector<bool>>::iterator itx = grid.begin(); itx != grid.end();
         itx++) {
      vector<char> row;
      for (vector<bool>::iterator ity = itx->begin(); ity != itx->end();
           ity++) {
#ifdef debug
        std::cout << *ity << " ";
#endif
        char c = *ity ? '1' : '0';
        row.push_back(c);
        uset.push_back(-1);
      }
#ifdef debug
      std::cout << "\n";
#endif
      cgrid.push_back(row);
    }

    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        if (cgrid[i][j] == '1') { //岛屿
          uset[posu(i, j)] = posu(i, j);
          // left
          if (inrange(i, j - 1) && cgrid[i][j - 1] == '1') {
            mix(posu(i, j), posu(i, j - 1));
          }
          if (inrange(i - 1, j) && cgrid[i - 1][j] == '1') { // up
            mix(posu(i, j), posu(i - 1, j));
          }
        }
      }
    }

    for (int i = 0; i < uset.size(); i++) {
#ifdef debug
      printf("\%d ", uset[i]);
#endif
      if (uset[i] != -1)
        uset[i] = find(uset[i]);
      flag.push_back('0');
      if (uset[i] != -1) {
        flag[uset[i]] = '1';
      }
    }
    int count = 0;
    for (int i = 0; i < uset.size(); i++) {
      if (flag[i] == '1')
        count++;
    }
    return count;
  }

  bool inrange(int i, int j) {
    if (i >= 0 && i < sizex && j >= 0 && j < sizey)
      return true;
    return false;
  }

  int posu(int i, int j) { return i * sizey + j; }
  void mix(int p1, int p2) {
#ifdef debug
    printf("mix %d %d\n", p1, p2);
#endif
    int ans;
    int r1 = find(p1);
    int r2 = find(p2);
    uset[r1] = r2;
  }

  int find(int p) {
    int r = p;
    while (r != uset[r])
      r = uset[r];
    int j;
    while (uset[p] != r) {
      j = uset[p];
      uset[p] = r;
      p = j;
    }
    return r;
  }
  int sizex;
  int sizey;
  vector<vector<char>> cgrid;
  vector<int> uset;
  vector<char> flag;
};

int main() {
  int arr1[] = {1, 1, 0, 0, 0};
  std::vector<bool> v1(arr1, arr1 + 5);
  int arr2[] = {0, 1, 0, 0, 1};
  std::vector<bool> v2(arr2, arr2 + 5);
  int arr3[] = {0, 0, 0, 1, 1};
  std::vector<bool> v3(arr3, arr3 + 5);
  int arr4[] = {0, 0, 0, 0, 0};
  std::vector<bool> v4(arr4, arr4 + 5);
  int arr5[] = {0, 0, 0, 0, 1};
  std::vector<bool> v5(arr5, arr5 + 5);

  vector<vector<bool>> grid;
  grid.push_back(v1);
  grid.push_back(v2);
  grid.push_back(v3);
  grid.push_back(v4);
  grid.push_back(v5);

  Solution s;
  std::cout << s.numIslands(grid) << std::endl;

  Solution s1;
  grid.clear();
  std::cout << s1.numIslands(grid) << std::endl;

  Solution s2;
  grid.clear();
  int arr0[] = {1, 1, 0, 1, 0, 0};
  vector<bool> v0(arr0, arr0 + 6);
  grid.push_back(v0);
  std::cout << s2.numIslands(grid) << std::endl;
  return 0;
}
