#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode() : val(0), left(NULL), right(NULL) {}
};
class Solution {
public:
  vector<vector<int>> Print(TreeNode *pRoot) {
    vector<vector<int>> result;
    vector<int> line;
    stack<TreeNode *> levels[2];
    int current = 0;

    if (pRoot == NULL)
      return result;

    levels[current].push(pRoot);

    while (!levels[0].empty() || !levels[1].empty()) {
      TreeNode *cur = levels[current].top();
      levels[current].pop();
      line.push_back(cur->val);

      if (current == 0) {
        if (cur->left != NULL)
          levels[1 - current].push(cur->left);
        if (cur->right != NULL)
          levels[1 - current].push(cur->right);
      } else {
        if (cur->right != NULL)
          levels[1 - current].push(cur->right);
        if (cur->left != NULL)
          levels[1 - current].push(cur->left);
      }

      if (levels[current].empty()) {
        current = 1 - current;
        result.push_back(line);
        line.erase(line.begin(), line.end());
      }
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  struct TreeNode nodes[32];

  for (int i = 0; i < 32; i++) {
    nodes[i] = i + 1;
    if (i * 2 + 1 <= 31)
      nodes[i].left = nodes + i * 2 + 1;
    if (i * 2 + 2 <= 31)
      nodes[i].right = nodes + i * 2 + 2;
  }
  auto result =  Solution().Print(nodes);

  return 0;
}
