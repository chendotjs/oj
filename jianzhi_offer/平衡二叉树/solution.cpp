class Solution {
public:
  bool flag;
  bool IsBalanced_Solution(TreeNode *pRoot) {
    flag = true;
    IsBalanced(pRoot);
    return flag;
  }

  int IsBalanced(TreeNode *pRoot) {
    if (pRoot == NULL)
      return 0;
    int left = IsBalanced(pRoot->left);
    int right = IsBalanced(pRoot->right);
    if (left - right > 1 || right - left > 1)
      flag = false;

    return left > right ? left + 1 : right + 1;
  }
};
