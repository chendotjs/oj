#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

string strArr[1001];

bool strCmp(const string &a, const string &b) {
  const char *str1 = a.c_str();
  const char *str2 = b.c_str();
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int minlen = len1 < len2 ? len1 : len2;
  for (int i = 0; i < minlen; i++) {
    if (str1[i] < str2[i]) {
      return true;
    } else if (str1[i] > str2[i]) {
      return false;
    }
  }
  return len1 < len2 ? true : false;
}

int main(int argc, char const *argv[]) {
  // freopen("in.txt", "r", stdin);
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++)
      std::cin >> strArr[i];
    std::sort(strArr, strArr + n, strCmp);
    for (int i = 0; i < n; i++)
      std::cout << strArr[i] << std::endl;
  }
  return 0;
}
