#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<string> result;
  set<string> S;
  string path;
  bool visited[100];
  vector<string> Permutation(string str) {
    path = string(str);
    for (int i = 0; i < 100; i++)
      visited[i] = false;

    if (str.size() == 0)
      return result;

    Permutation(str, 0);
    for (auto &str : S) {
      // cout << str << endl;
      result.push_back(str);
    }
    return result;
  }
  void Permutation(string str, int level) {
    if (level == str.size()) {
      // cout << path << endl;
      S.insert(path);
      return;
    }
    for (int i = 0; i < str.size(); i++) {
      if (visited[i] == false) {
        visited[i] = true;
        path[level] = str[i];
        Permutation(str, level + 1);
        visited[i] = false;
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  { Solution().Permutation("abc"); }

  { Solution().Permutation("bacd"); }

  { Solution().Permutation("aa"); }
  return 0;
}
