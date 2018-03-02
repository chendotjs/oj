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
  vector<int> PrintFromTopToBottom(TreeNode *root) {
    vector<int> result;
    if (root == NULL)
      return result;
    Q.push(root);
    while (Q.empty() == false) {
      TreeNode *cur = Q.front();
      Q.pop();
      result.push_back(cur->val);
      if (cur->left != NULL)
        Q.push(cur->left);
      if (cur->right != NULL)
        Q.push(cur->right);
    }
    return result;
  }
};
