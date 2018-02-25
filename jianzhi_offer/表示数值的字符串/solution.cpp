#include <iostream>
using namespace std;

class Solution {
public:
  int transitionTable[8][5] = {
      // digit0 +/-1 e/E2 .3 invalid4
      {1, 2, -1, 3, -1},   // 0
      {1, -1, 5, 4, -1},   // 1
      {1, -1, -1, 3, -1},  // 2
      {4, -1, -1, -1, -1}, // 3
      {4, -1, 5, -1, -1},  // 4
      {7, 6, -1, -1, -1},  // 5
      {7, -1, -1, -1, -1}, // 6
      {7, -1, -1, -1, -1}  // 7
  };
  bool isNumeric(char *string) {
    if (string == NULL)
      return true;
    int state = 0;
    int condition;
    for (int i = 0; string[i] != '\0'; i++) {
      char c = string[i];
      condition = 4;
      if (c >= '0' && c <= '9')
        condition = 0;
      if (c == '+' || c == '-')
        condition = 1;
      if (c == 'E' || c == 'e')
        condition = 2;
      if (c == '.')
        condition = 3;
      state = transitionTable[state][condition];
      if (state == -1)
        return false;
    }
    if (state == 1 || state == 4 || state == 7)
      return true;
    return false;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.isNumeric("a") << endl;
  cout << s.isNumeric("+100") << endl;
  cout << s.isNumeric("-1.1") << endl;
  cout << s.isNumeric("100") << endl;
  cout << s.isNumeric("54e2") << endl;
  cout << s.isNumeric("11.22") << endl;
  cout << s.isNumeric("-1.1E-7") << endl;


  cout << s.isNumeric("-1.1E-7.0") << endl;
  cout << s.isNumeric("-1.2.0") << endl;


  return 0;
}
