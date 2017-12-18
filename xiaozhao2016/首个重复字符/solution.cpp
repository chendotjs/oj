#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class FirstRepeat {
public:
  bool flag[128];
  char findFirstRepeat(string A, int n) {
    memset(flag, 0, sizeof(flag));
    for (int i  = 0; i < n; i++) {
      if (flag[A[i]] == false) {
        flag[A[i]] = true;
      } else {
        return A[i];
      }
    }
    return 0;
  }
};

int main(int argc, char const *argv[]) {
  {
    FirstRepeat s;
    string A = "qywyer23tdd";
    std::cout << s.findFirstRepeat(A, A.size()) << endl;
  }
  return 0;
}
