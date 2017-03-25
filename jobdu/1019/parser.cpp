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
term ::= num * term | num / term | num
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
int currentPointer = 0;

typedef struct lexEle {
  int type;
  union {
    char op;
    int num;
  } content;
} lexEle;

std::vector<lexEle> lexVector;
int lexSize;

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
  lexSize = lexVector.size();
#if 0
  traverse(lexVector) {
    if (it->type == Operator) {
      printf("%c\n", it->content.op);
    } else {
      printf("%d\n", it->content.num);
    }
  }
#endif
}

typedef struct ASTNode {
  char op;
  int num;
  ASTNode *lchild;
  ASTNode *rchild;
} ASTNode;

ASTNode *num(int index) {
  ASTNode *nodePtr = new ASTNode();
  if (index >= lexSize)
    return NULL;
  if (lexVector[index].type == Number) {
    nodePtr->num = lexVector[index].content.num;
    nodePtr->op = ' ';
    nodePtr->lchild = nodePtr->rchild = NULL;
    currentPointer++;
  }
  return nodePtr;
}

ASTNode *term(int index) {
  ASTNode *nodePtr = new ASTNode();

  if (index + 1 < lexSize && lexVector[index + 1].type == Operator &&
      (lexVector[index + 1].content.op == '*' ||
       lexVector[index + 1].content.op == '/')) {
    nodePtr->lchild = num(index);
    nodePtr->op = lexVector[index + 1].content.op;
    currentPointer++;
    nodePtr->rchild = term(index + 2);
  } else {
    nodePtr = num(index);
  }
  return nodePtr;
}

ASTNode *expr(int index) {
  ASTNode *nodePtr;
  ASTNode *termPtr = term(index);
  if (currentPointer < lexSize && lexVector[currentPointer].type == Operator &&
      (lexVector[currentPointer].content.op == '+' ||
       lexVector[currentPointer].content.op == '-')) {
    nodePtr = new ASTNode();
    nodePtr->lchild = termPtr;
    nodePtr->op = lexVector[currentPointer].content.op;
    currentPointer++;
    nodePtr->rchild = expr(currentPointer);
  } else {
    nodePtr = termPtr;
  }

  return nodePtr;
}

ASTNode *parser(std::vector<lexEle> &lexVector) {
  currentPointer = 0;
  return expr(currentPointer);
}

/**
为了避免左递归，生成的语法树和普通的运算顺序是相悖的，比如3-4+5
    -
  /  \
3    +
    / \
  4    5
在generator中做了一些处理
*/
double generator(ASTNode *root, char previousOP, bool rchild) {
  if (root->op != '+' && root->op != '-' && root->op != '*' &&
      root->op != '/') {
    return (double)root->num;
  }
  switch (root->op) {
  case '+': {
    if (previousOP == '-' && rchild) {
      return generator(root->lchild, root->op, false) -
             generator(root->rchild, root->op, true);
    }
    return generator(root->lchild, root->op, false) +
           generator(root->rchild, root->op, true);
  }
  case '-': {
    if (previousOP == '-' && rchild) {
      return generator(root->lchild, root->op, false) +
             generator(root->rchild, root->op, true);
    }
    return generator(root->lchild, root->op, false) -
           generator(root->rchild, root->op, true);
  }
  case '*': {
    if (previousOP == '/' && rchild) {
      return generator(root->lchild, root->op, false) /
             generator(root->rchild, root->op, true);
    }
    return generator(root->lchild, root->op, false) *
           generator(root->rchild, root->op, true);
  }
  case '/': {
    if (previousOP == '/' && rchild) {
      return generator(root->lchild, root->op, false) *
             generator(root->rchild, root->op, true);
    }
    return generator(root->lchild, root->op, false) /
           generator(root->rchild, root->op, true);
  }
  }
}

int main() {
  while (fgets(expression, 240, stdin)) {
    length = strlen(expression);
    expression[length - 1] = '\0';
    length--;
    if (expression[0] == '0' && length == 1)
      return 0;
    currentPointer = 0;
    lexVector.clear();
    lexer(expression);
    ASTNode *root = parser(lexVector);

    printf("%.2lf\n", generator(root, ' ', false));
  }
}
