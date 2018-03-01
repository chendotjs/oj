#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  void Mirror(TreeNode *pRoot) {
    if (pRoot == NULL)
      return;
    TreeNode *old_left = pRoot->left;
    TreeNode *old_right = pRoot->right;

    pRoot->left = old_right;
    pRoot->right = old_left;

    Mirror(old_left);
    Mirror(old_right);
  }
};
