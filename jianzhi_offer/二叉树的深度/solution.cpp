#include <algorithm>
#include <iostream>
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
  int depth;
  int TreeDepth(TreeNode *pRoot) {
    if (pRoot == NULL)
      return 0;
    depth = 0;
    vector<TreeNode *> stk;
    preorder(pRoot, stk);
    return depth;
  }

  void preorder(TreeNode *pRoot, vector<TreeNode *> &stk) {
    stk.push_back(pRoot);
    if (pRoot->left == NULL && pRoot->right == NULL) {
      depth = depth > stk.size() ? depth : stk.size();
    }

    if (pRoot->left) {
      preorder(pRoot->left, stk);
    }

    if (pRoot->right) {
      preorder(pRoot->right, stk);
    }
    stk.pop_back();
  }
};


int main(int argc, char const *argv[]) {
  {
    TreeNode nodes[] = {1,2,3};
    nodes[0].left = nodes + 1;
    nodes[1].left = nodes + 2;
    cout << Solution().TreeDepth(nodes) << endl;
  }
  return 0;
}
