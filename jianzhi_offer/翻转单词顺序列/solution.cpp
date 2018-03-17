#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string ReverseSentence(string str) {
    if (str.size() == 0)
      return str;

    Reverse(str, 0, str.size() - 1);
    int ahead = 0, behind = 0;
    while (ahead < str.size() && str[ahead] == ' ') {
      ahead++;
      behind++;
    }
    while (ahead < str.size()) {
      while (behind <= str.size() - 1 && str[behind] != ' ') {
        behind++;
      }

      Reverse(str, ahead, behind - 1);
      ahead = behind + 1;
      behind++;
    }
    return str;

  }
  void Reverse(string &str, int i, int j) {
    if (i >= j)
      return;

    int ahead = i, behind = j;
    while (ahead < behind) {
      char temp = str[ahead];
      str[ahead] = str[behind];
      str[behind] = temp;

      ahead++;
      behind--;
    }
  }
};

int main(int argc, char const *argv[]) {
  {
    string s("abc def");
    cout << Solution().ReverseSentence(s)<< endl;
  }

  {
    string s("I am a student.");
    cout << Solution().ReverseSentence(s)<< endl;
  }

  {
    string s(" I am a student. ");
    cout << Solution().ReverseSentence(s)<< endl;
  }
  return 0;
}
