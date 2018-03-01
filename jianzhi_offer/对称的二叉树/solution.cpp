#include <iostream>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  bool isSymmetrical(TreeNode *pRoot) {
    if (pRoot == NULL)
      return true;
    return isSymmetrical(pRoot->left, pRoot->right);
  }

  bool isSymmetrical(TreeNode *pRoot1, TreeNode *pRoot2) {
    if (pRoot1 == NULL && pRoot2 == NULL)
      return true;
    if (pRoot1 == NULL || pRoot2 == NULL)
      return false;

    // 类似判断两个树相等
    if (pRoot1->val == pRoot2->val) {
      return isSymmetrical(pRoot1->left, pRoot2->right) &&
             isSymmetrical(pRoot1->right, pRoot2->left);
    } else
      return false;
  }
};
