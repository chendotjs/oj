#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
using namespace std;

class Solution {

public:
  priority_queue<int, vector<int>, less<int>> p;    //最大堆
  priority_queue<int, vector<int>, greater<int>> q; // 最小堆
  void Insert(int num) {
    if (p.empty() || num < p.top()) {
      p.push(num);
    } else
      q.push(num);
    if (p.size() == q.size() + 2) {
      q.push(p.top());
      p.pop();
    }

    if (p.size() + 1 == q.size()) {
      p.push(q.top());
      q.pop();
    }
  }

  double GetMedian() {
    if (p.size() == q.size())
      return p.top() + (q.top() - p.top()) / 2.0;
    return p.top();
  }
};


int main(int argc, char const *argv[]) {

  return 0;
}
