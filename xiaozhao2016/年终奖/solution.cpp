#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Bonus {
public:
  int max(int i, int j) { return i > j ? i : j; }
  int value[7][7];
  int getMost(vector<vector<int>> board) {
    memset(value, 0, sizeof(value));
    value[1][1] = board[0][0];
    for (int i = 1; i <= board.size(); i++) {
      for (int j = 1; j <= board.size(); j++) {
        if (i == 1 && j == 1)
          continue;
        value[i][j] =
            max(value[i - 1][j], value[i][j - 1]) + board[i - 1][j - 1];
      }
    }
    return value[board.size()][board.size()];
  }
};

int main() {
  {
    vector<vector<int>> imatrix = {{1, 2, 4, 5, 7, 8},   {1, 2, 4, 5, 7, 6},
                                   {1, 2, 4, 5, 7, 5},   {1, 2, 4, 5, 7, 2},
                                   {1, 2, 4, 5, 5, 100}, {1, 2, 4, 5, 7, 1}};
    Bonus s;
    int ans = s.getMost(imatrix);
    cout << ans << endl; // 146
  }

  {
    vector<vector<int>> imatrix = {
        {564, 448, 654, 186, 490, 699}, {487, 444, 563, 228, 365, 261},
        {429, 505, 612, 564, 715, 726}, {464, 617, 234, 647, 702, 263},
        {245, 249, 231, 462, 453, 646}, {669, 510, 492, 512, 622, 135}};
    Bonus s;
    int ans = s.getMost(imatrix);
    cout << ans << endl;
    /**
     *
        564     1012    1666    1852    2342    3041   
        1051    1495    2229    2457    2822    3302   
        1480    2000    2841    3405    4120    4846   
        1944    2617    3075    4052    4822    5109   
        2189    2866    3306    4514    5275    5921   
        2858    3376    3868    5026    5897    6056
     */
  }

  return 0;
}

