#include <iostream>
using namespace std;

class Solution {
public:
  bool match(char *str, char *pattern) {
    if (str == NULL || pattern == NULL)
      return false;
    return rec_match(str, pattern);
  }

  bool rec_match(char *str, char *pattern) {
    if (*str == '\0' && *pattern == '\0')
      return true;
    if (*pattern == '\0' && *str != '\0')
      return false;

    if (*(pattern + 1) == '*') {
      if (*pattern == *str || (*pattern == '.' && *str != '\0'))
        return rec_match(str + 1, pattern) || rec_match(str + 1, pattern + 2) ||
               rec_match(str, pattern + 2);
      else
        return rec_match(str, pattern + 2);
    }
    if (*str == *pattern || (*pattern == '.' && *str != '\0'))
      return rec_match(str + 1, pattern + 1);
    return false;
  }
};

int main(int argc, char const *argv[]) {
  {
    Solution s;
    char *str = "abbbc";
    char *pattern = "ab*c";
    cout << s.match(str, pattern) << endl;
  }

  {
    Solution s;
    char *str = "aaa";
    char *pattern = "ab*ac*a";
    cout << s.match(str, pattern) << endl;
  }

  {
    Solution s;
    char *str = "aaa";
    char *pattern = "aa.a";
    cout << s.match(str, pattern) << endl;
  }

  {
    Solution s;
    char *str = "";
    char *pattern = "a*a";
    cout << s.match(str, pattern) << endl;
  }

  {
    Solution s;
    char *str = "";
    char *pattern = "a*b*";
    cout << s.match(str, pattern) << endl;
  }

  {
    Solution s;
    char *str = "";
    char *pattern = "a*b*c";
    cout << s.match(str, pattern) << endl;
  }

  {
    Solution s;
    char *str = "";
    char *pattern = "abcc";
    cout << s.match(str, pattern) << endl;
  }

  {
    Solution s;
    char *str = "ab";
    char *pattern = "abcc";
    cout << s.match(str, pattern) << endl;
  }

  {
    Solution s;
    char *str = "b";
    char *pattern = ".*";
    cout << s.match(str, pattern) << endl;
  }

  {
    Solution s;
    char *str = "aaa";
    char *pattern = "a*a";
    cout << s.match(str, pattern) << endl;
  }
  return 0;
}
