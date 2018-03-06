#include <iostream>
/**
 * 递归方法
 * prev节点保存上一个当前节点的前驱节点，作为全局变量。
 * 下面的步骤就是魔改 中序遍历 了， 修改 `visit` 函数
 *
 * 当前结点指向左指针指向前驱结点
 * 前驱结点右指针指向当前结点
 * 前驱 = 当前
 */
using namespace std;
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *prev;
  TreeNode *Convert(TreeNode *pRootOfTree) {
    if (pRootOfTree == NULL)
      return NULL;

    prev = NULL; // 最小节点的左指针为NULL
    traverse(pRootOfTree);

    while (pRootOfTree->left) {
      pRootOfTree = pRootOfTree->left;
    }
    return pRootOfTree;
  }
  void traverse(TreeNode *node) {
    if (node == NULL)
      return;

    TreeNode *cur = node;
    if (cur->left)
      traverse(cur->left);

    cur->left = prev;
    if (prev)
      prev->right = cur;
    prev = cur;

    if (cur->right)
      traverse(cur->right);
  }
};

int main(int argc, char const *argv[]) {
  {}
  return 0;
}
