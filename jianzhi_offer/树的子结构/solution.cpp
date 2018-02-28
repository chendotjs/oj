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
  bool TreeEqual(TreeNode *pRoot1, TreeNode *pRoot2) {
    if (pRoot1 == NULL && pRoot2 == NULL)
      return true;
    if (pRoot1 == NULL && pRoot2 != NULL)
      return false;
    if (pRoot1 != NULL && pRoot2 == NULL)
      return true;

    if (pRoot1->val == pRoot2->val) {
      return TreeEqual(pRoot1->left, pRoot2->left) &&
             TreeEqual(pRoot1->right, pRoot2->right);
    } else
      return false;
  }

  bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
    bool result = false;
    if (pRoot1 != NULL && pRoot2 != NULL) {
      if (pRoot1->val == pRoot2->val) {
        result = TreeEqual(pRoot1, pRoot2);
      }
      if (!result)
        result = HasSubtree(pRoot1->left, pRoot2) ||
                 HasSubtree(pRoot1->right, pRoot2);
    }
    return result;
  }
};
