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
  vector<vector<int>> result;
  vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
    vector<int> path;
    result.erase(result.begin(), result.end());

    dfs(root, 0, expectNumber, path);
    return result;
  }

  void dfs(TreeNode *node, int sum, int expectNumber, vector<int> &path) {
    if (node == NULL)
      return;

    path.push_back(node->val);
    if (node->left == NULL && node->right == NULL) {
      if (expectNumber == sum + node->val) {
        result.push_back(path);
      }
      path.pop_back();
      return;
    }

    if (node->left) {
      dfs(node->left, sum + node->val, expectNumber, path);
    }

    if (node->right) {
      dfs(node->right, sum + node->val, expectNumber, path);
    }

    path.pop_back();
  }
};

int main(int argc, char const *argv[]) {
  TreeNode nodes[5] = {10, 5, 12, 4, 7};
  nodes[0].left = nodes + 1;
  nodes[0].right = nodes + 2;
  nodes[1].left = nodes + 3;
  nodes[1].right = nodes + 4;

  auto result = Solution().FindPath(nodes, 22);
  result = Solution().FindPath(nodes, 100);
  result = Solution().FindPath(nodes, 19);

  return 0;
}
