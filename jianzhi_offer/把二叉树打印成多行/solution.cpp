#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  queue<TreeNode *> Q;
  vector<vector<int>> Print(TreeNode *pRoot) {
    vector<vector<int>> result;
    vector<int> line;
    int nextLevel = 0;
    int left = 1;

    if (pRoot == NULL) return result;
    Q.push(pRoot);
    while (Q.empty() == false) {
      TreeNode *cur = Q.front();
      Q.pop();
      left--;
      line.push_back(cur->val);

      if (cur->left != NULL) {
        nextLevel++;
        Q.push(cur->left);
      }

      if (cur->right != NULL) {
        nextLevel++;
        Q.push(cur->right);
      }

      if (left == 0) {
        result.push_back(line);
        line.erase(line.begin(), line.end());
        left= nextLevel;
        nextLevel = 0;
      }
    }
    return result;
  }
};
