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
  bool flag;
  TreeNode *res;
  TreeNode *KthNode(TreeNode *pRoot, int k) {
    flag = false;
    res = NULL;
    if (k == 0 || pRoot == NULL)
      return NULL;
    KthNode(pRoot, &k);
    return res;
  }
  void KthNode(TreeNode *pRoot, int *k) {
    if (flag)
      return;

    if (pRoot->left) {
      KthNode(pRoot->left, k);
    }

    (*k)--;
    if (*k == 0) {
      res = pRoot;
      flag = true;
      return;
    }

    if (pRoot->right) {
      KthNode(pRoot->right, k);
    }
  }
};

int main(int argc, char const *argv[]) {
  struct TreeNode nodes[] = {5, 3, 7, 2, 4, 6, 8};
  for (int i = 0; i < 3; i++) {
    nodes[i].left = nodes + i * 2 + 1;
    nodes[i].right = nodes + i * 2 + 2;
  }

  cout << Solution().KthNode(nodes, 1)->val << endl;
  cout << Solution().KthNode(nodes, 2)->val << endl;
  cout << Solution().KthNode(nodes, 3)->val << endl;
  cout << Solution().KthNode(nodes, 4)->val << endl;
  cout << Solution().KthNode(nodes, 7)->val << endl;
  cout << Solution().KthNode(nodes, 8)->val << endl;
  return 0;
}
