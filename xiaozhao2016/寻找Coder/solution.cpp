#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct E {
  int index;
  int cnt;
  bool operator<(const struct E &x) const { return cnt > x.cnt; }
};

class Coder {
public:
  vector<string> findCoder(vector<string> A, int n) {
    // write code here
    vector<struct E> B(A.size());
    vector<string> ans;
    for (int i = 0; i < B.size(); i++) {
      int cnt = 0;
      unsigned int pos = 0;
      string str = A[i];
      for (int i = 0; i < str.size(); i++) {
        if (isupper(str[i])) {
          str[i] = tolower(str[i]);
        }
      }
      while ((pos = str.find("coder", pos)) != -1) {
        pos++;
        cnt++;
      }

      B[i].cnt = cnt;
      B[i].index = i;
    }

    stable_sort(B.begin(), B.end());
    for (int i = 0; i < B.size(); i++) {
      if (B[i].cnt != 0) {
        ans.push_back(A[B[i].index]);
      } else
        break;
    }
    return ans;
  }
};

int main() {
  {
    Coder s;
    vector<string> svec = {"i am a coder", "Coder Coder", "Code"};
    vector<string> const &ans = s.findCoder(svec, svec.size());
    for (auto item : ans) {
      std::cout << item << std::endl;
    }
    std::cout << std::endl;
  }

  {
    Coder s;
    vector<string> svec = {"i am a coder", "Coder Coder",
                           "Codercodercoder Coder"};
    vector<string> const &ans = s.findCoder(svec, svec.size());
    for (auto item : ans) {
      std::cout << item << std::endl;
    }
    std::cout << std::endl;
  }

  {
    Coder s;
    vector<string> svec = {"i am a coder", "Coder Coder",
                           "Codercodercoder Coder", "i am a coder coder"};
    vector<string> const &ans = s.findCoder(svec, svec.size());
    for (auto item : ans) {
      std::cout << item << std::endl;
    }
    std::cout << std::endl;
  }

  return 0;
}
