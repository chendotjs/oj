#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  char _map[300];
  int FirstNotRepeatingChar(string str) {
    memset(_map, 0, sizeof(_map));
    for (auto &c : str) {
      _map[(int)c]++;
    }

    for (int i = 0; i < str.size(); i++) {
      int c = str[i];
      if (_map[(int)c] == 1) {
        return i;
      }
    }
    return -1;
  }
};
