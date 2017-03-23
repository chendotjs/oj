#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

char str[200];
char result[200];

typedef struct pair {
  char c;
  int index;
} Pair;

int main() {
  while (scanf("%s", str) != EOF) {
    stack<Pair> s;
    int length = strlen(str);
    memset(result, ' ', 200);
    result[length] = '\0';

    for (int i = 0; i < length; i++) {
      if (str[i] == '(' || str[i] == ')') {
        Pair p = {str[i], i};
        if (s.size() > 0) {
          // match then pop
          Pair top = s.top();
          if (str[i] == ')' && top.c == '(')
            s.pop();
          else
            s.push(p);
        } else {
          s.push(p);
        }
      }
    }
    while (s.size() > 0) {
      Pair top = s.top();
      s.pop();
      result[top.index] = top.c == ')' ? '?' : '$';
    }
    printf("%s\n", str);
    printf("%s\n", result);
  }
  return 0;
}
