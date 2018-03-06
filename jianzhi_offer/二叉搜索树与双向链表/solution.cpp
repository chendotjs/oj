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
  vector<TreeNode *> vec;
  TreeNode *Convert(TreeNode *pRootOfTree) {
    if (pRootOfTree == NULL) return NULL;
    traverse(pRootOfTree);

    for (int i = 0; i < vec.size() - 1; i++) {
      vec[i]->right = vec[i + 1];
    }
    for (int i = 1; i < vec.size(); i++) {
      vec[i]->left = vec[i - 1];
    }

    return vec[0];
  }

  void traverse(TreeNode *root) {
    if (root->left)
      traverse(root->left);
    vec.push_back(root);
    if (root->right)
      traverse(root->right);
  }

};


int main(int argc, char const *argv[]) {
  {

  }
  return 0;
}
