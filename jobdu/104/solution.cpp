#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main() {
  char str[101];
  fgets(str, 101, stdin);
  str[strlen(str) - 1] = '\0';

  string a = str;
  for (int i = 0; i < strlen(str); i++) {
    a[i] = tolower(a[i]);
  }

  while(fgets(str, 101, stdin) != NULL) {
    str[strlen(str) - 1] = '\0';
    string b = str;
    string c = str;

    for (int i = 0; i < strlen(str); i++) {
      b[i] = tolower(b[i]);
    }
    int pos = 0;
    while ((pos = b.find(a, pos)) != string::npos) {
      b.erase(pos, a.size());
      c.erase(pos, a.size());
    }
    pos = 0;
    while ((pos = c.find(" ", pos)) != string::npos) {
      c.erase(pos, 1);
    }
    std::cout << c << std::endl;

  }

  return 0;
}

