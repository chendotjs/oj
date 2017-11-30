#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int in_degree[2010];
map<string, int> M;

int main() {
  while (std::cin >> n && n != 0) {
    M.clear();
    memset(in_degree, 0, sizeof(in_degree));

    char str1[50];
    char str2[50];

    int idx = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s%s", str1, str2);
      string player1 = str1;
      string player2 = str2;

      if (M.find(player1) == M.end()) { // 1st appearance
        //std::cout << player1 << idx << std::endl;
        M[player1] = idx++;
      }
      int idx2;
      if (M.find(player2) == M.end()) { // 1st appearance
        idx2 = idx;
        //std::cout << player2 << idx << std::endl;
        M[player2] = idx++;
      } else
        idx2 = M[player2];
      in_degree[idx2]++;
    }
    int cnt = 0;
    for (int i = 0; i < idx; i++) {
      if (in_degree[i] == 0)
        cnt++;
    }

    cnt == 1 ? printf("Yes\n") : printf("No\n");
  }
  return 0;
}

