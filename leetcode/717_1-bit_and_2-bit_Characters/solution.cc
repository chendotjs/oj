#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  bool isOneBitCharacter(vector<int> &bits) {
    int size = bits.size();
    bool res;
    for (int i = 0; i < size;) {
      if (bits[i] == 0) {
        i++;
        res = true;
      } else {
        i += 2;
        res =  false;
      }
    }
    return res;
  }
};
