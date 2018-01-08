#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void postOrder(TreeNode *root) {
  if (root != NULL) {
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);
  }
}

class Solution {
public:
  TreeNode *construct(vector<int> &pre, vector<int> &vin, int pre_start,
                      int pre_end, int in_start, int in_end) {
    TreeNode *root = new TreeNode(pre[pre_start]);

    int rootIdx = in_start;
    for (int i = in_start; i <= in_end; i++) {
      if (root->val == vin[i]) {
        rootIdx = i;
        break;
      }
    }
    int lclen = rootIdx - in_start;
    int rclen = in_end - rootIdx;
    if (lclen > 0)
      root->left = construct(pre, vin, pre_start + 1, pre_start + lclen, in_start, rootIdx - 1);
    if (rclen > 0)
      root->right = construct(pre, vin, pre_start + lclen + 1, pre_end, rootIdx + 1, in_end);
    return root;
  }
  TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    int size = pre.size();
    return construct(pre, vin, 0, size - 1, 0, size - 1);
  }
};


int main(int argc, char const *argv[]) {
  {
    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode *root = Solution().reConstructBinaryTree(pre, vin);
    postOrder(root);
  }
  return 0;
}
