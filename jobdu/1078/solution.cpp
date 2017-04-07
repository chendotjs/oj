#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

// #define DEBUG
/**
样例输入：
ABC
BAC
FDXEAG
XDEFAG
样例输出：
BCA
XEDGAF
*/

typedef struct Node {
  Node *lchild;
  Node *rchild;
  char c;
} Node;

char preOrderSeq[30];
char midOrderSeq[30];
Node Btree[30];
int BTpos = 0;
int length;

Node *createNode(char c) {
  Btree[BTpos].c = c;
  Btree[BTpos].lchild = Btree[BTpos].rchild = NULL;
  return Btree + (BTpos++);
}

int pos(char c, char *str, int begin, int end) {
  for (int i = begin; i <= end; i++) {
    if (c == str[i])
      return i;
  }
  return -1;
}

Node *createTree(int pbegin, int pend, int mbegin, int mend) {
  int rootIndex = pos(preOrderSeq[pbegin], midOrderSeq, mbegin, mend);
  Node *rootPtr = createNode(preOrderSeq[pbegin]);
#ifdef DEBUG
  printf("%d %d %d %d\n", pbegin + 1, pbegin + rootIndex - mbegin, mbegin,
         rootIndex - 1);
  printf("%d %d %d %d\n", pbegin + rootIndex - mbegin + 1, pend, rootIndex + 1,
         mend);
#endif
  if (rootIndex != mbegin) //************左子树不为空
    rootPtr->lchild = createTree(pbegin + 1, pbegin + rootIndex - mbegin,
                                 mbegin, rootIndex - 1);
  if (rootIndex != mend) //************右子树不为空
    rootPtr->rchild =
        createTree(pbegin + rootIndex - mbegin + 1, pend, rootIndex + 1, mend);
  return rootPtr;
}

void postOrder(Node * root) {
  if(root->lchild) {
    postOrder(root->lchild);
  }

  if(root->rchild) {
    postOrder(root->rchild);
  }
  printf("%c", root->c);
}
int main() {
  while (scanf("%s%s", preOrderSeq, midOrderSeq) != EOF) {
    memset(Btree, 0, sizeof(Btree));
    BTpos = 0;
    length = strlen(preOrderSeq);
    Node * root = createTree(0, length - 1, 0, length - 1);
    postOrder(root);
    printf("\n");
  }
  return 0;
}
