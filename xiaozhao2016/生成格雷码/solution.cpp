#include <iostream>
#include <vector>
#include <string>

using namespace std;

class GrayCode {
public:
    vector<string> getGray(int n) {
      vector<string> ans;
      if (n == 1) {
        ans = {"0", "1"};
        return ans;
      }

      const vector<string> &pre = getGray(n - 1);
      for (int i = 0; i < pre.size(); i++) {
        ans.push_back(string("0") + pre[i]);
      }
      for (int i = pre.size() - 1; i >= 0; i--) {
        ans.push_back(string("1") + pre[i]);
      }
      return ans;
    }
};

int main() {
  {
    GrayCode s;
    const vector<string> & ans = s.getGray(1);
    for (auto &item : ans) {
      cout << item << endl;
    }
    cout << endl;
  }

  {
    GrayCode s;
    const vector<string> & ans = s.getGray(2);
    for (auto &item : ans) {
      cout << item << endl;
    }
    cout << endl;
  }
  {
    GrayCode s;
    const vector<string> & ans = s.getGray(3);
    for (auto &item : ans) {
      cout << item << endl;
    }
    cout << endl;
  }
  return 0;
}

