#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
/**
 * 返回git树上两点的最近分割点
 *
 * @param matrix 接邻矩阵，表示git树，matrix[i][j] == '1'
 * 当且仅当git树中第i个和第j个节点有连接，节点0为git树的跟节点
 * @param indexA 节点A的index
 * @param indexB 节点B的index
 * @return 整型
 */
#define LENGTH 10000
  int in_degree[LENGTH];
  int parent[LENGTH];
  queue<int> Q;

  vector<int> pathA;
  vector<int> pathB;

  void makePath(vector<string> &matrix, int index, vector<int> &path) {
    int father = index;
    path.push_back(father);
    while (father != 0) {
      father = parent[father];
      path.push_back(father);
    }
  }

  int getSplitNode(vector<string> matrix, int indexA, int indexB) {
    memset(in_degree, 0, sizeof(in_degree));
    memset(parent, 0, sizeof(parent));
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix.size(); j++) {
        if (matrix[i][j] == '1') {
          in_degree[i]++;
        }
      }
    }

    // 类似拓扑排序
    for (int i = 0; i < matrix.size(); i++) {
      if (in_degree[i] == 1 && i != 0)
        Q.push(i);
    }
    while (Q.empty() == false) {
      int cur = Q.front();
      Q.pop();
      // printf("handle %d\n", cur);
      in_degree[cur]--;
      for (int i = 0; i < matrix.size(); i++) {
        if (matrix[cur][i] == '1') {
          matrix[i][cur] = '0';
          in_degree[i]--;
          parent[cur] = i;
          if (in_degree[i] == 1 && i != 0) // root not added
            Q.push(i);
          break;
        }
      }
    }

    makePath(matrix, indexA, pathA);
    makePath(matrix, indexB, pathB);

    int ans = 0;
    for (int i = 0; i < pathA.size(); i++) {
      for (int j = 0; j < pathB.size(); j++) {
        if (pathA[i] == pathB[j]) {
          ans = pathA[i];
          goto result;
        }
      }
    }
  result:
    return ans;
  }
};

int main() {

  {
    vector<string> svec = {"01011000", "10100000", "01000000", "10000110",
                           "10000000", "00010000", "00010001", "00000010"};
    Solution s;
    cout << s.getSplitNode(svec, 2, 7) << endl;
  }

  {
    vector<string> svec = {"01011000", "10100000", "01000000", "10000110",
                           "10000000", "00010000", "00010001", "00000010"};
    Solution s;
    cout << s.getSplitNode(svec, 5, 7) << endl;
  }

  {
    vector<string> svec = {"01011", "10100", "01000", "10000", "10000"};
    Solution s;
    cout << s.getSplitNode(svec, 1, 2) << endl;
  }

  {
    vector<string> svec = {"0000001000","0000000100","0000011100","0000010000","0000001010","0011000001","1010100000","0110000000","0000100000","0000010000"};
    Solution s;
    cout << s.getSplitNode(svec, 3, 8) << endl; // 6
  }

  return 0;
}
