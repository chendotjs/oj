#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
#define traverse(v)                                                            \
  for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

/**
expr ::= term +|- expr | term
term ::= num * num | num / num | num
num ::= [0-9]*
*/

/**
example:
1 + 2
4 + 2 * 5 - 7 / 11
3 * 4
*/
char expression[250];
int length;
enum { Operator, Number };

typedef struct lexEle {
  int type;
  union {
    char op;
    int num;
  } content;
} lexEle;

std::vector<lexEle> lexVector;

void lexer(char *expression) {
  for (int i = 0; i < length; i++) {
    char currentChar = expression[i];
    if (currentChar == ' ')
      continue;
    else if (currentChar == '+' || currentChar == '-' || currentChar == '*' ||
             currentChar == '/') {
      lexEle ele = {Operator, currentChar};
      lexVector.push_back(ele);
    } else if (currentChar >= '0' && currentChar <= '9') {
      // transform to number
      char *endptr = NULL;
      int number = strtod(expression + i, &endptr);
      while (endptr != expression + i) {
        i++;
      }
      i--;

      lexEle ele = {Number, number};
      lexVector.push_back(ele);
    }
  }
#if 1
  traverse(lexVector) {
    if(it->type == Operator) {
      printf("%c\n", it->content.op);
    } else {
      printf("%d\n", it->content.num);
    }
  }
#endif
}

int main() {
  while (fgets(expression, 240, stdin)) {
    length = strlen(expression);
    expression[length - 1] = '\0';
    length--;
    if (expression[0] == '0' && length == 1)
      return 0;
    lexer(expression);
  }
}
