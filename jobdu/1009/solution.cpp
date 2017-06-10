#include <cstdio>
#include <cstring>
#include <iostream>

#define LENGTH 100
int n;

char origin[100];
int originindex = 0;

struct Node {
  struct Node *lchild, *rchild;
  char value;
};

struct Node container[LENGTH];

char preOrdero[LENGTH];
char midOrdero[LENGTH];

char preOrdertest[LENGTH];
char midOrdertest[LENGTH];

void addNode(char c, struct Node *root) {
  if (c >= root->value) {
    if (root->rchild == NULL) {
      root->rchild = container + originindex - 1;
    } else {
      addNode(c, root->rchild);
    }
  } else if (c < root->value) {
    if (root->lchild == NULL) {
      root->lchild = container + originindex - 1;
    } else {
      addNode(c, root->lchild);
    }
  }
}

void createTree() {
  // init
  memset(container, 0, sizeof(container));
  originindex = 0;

  container[originindex++].value = origin[0];
  for (int i = 1; i < strlen(origin); i++) {
    container[originindex++].value = origin[i];
    addNode(origin[i], container);
  }
}

void preOrder(struct Node *root, char *str, int *pos) {
  if (root == NULL)
    return;
  str[*pos] = root->value;
  (*pos)++;
  preOrder(root->lchild, str, pos);
  preOrder(root->rchild, str, pos);
}

void midOrder(struct Node *root, char *str, int *pos) {
  if (root == NULL)
    return;
  midOrder(root->lchild, str, pos);
  str[*pos] = root->value;
  (*pos)++;
  midOrder(root->rchild, str, pos);
}

int main() {
  while (scanf("%d", &n) != EOF) {
    if (n == 0) {
      return 0;
    }
    std::cin >> origin;
    createTree();

    int index = 0;
    preOrder(container, preOrdero, &index);
#ifdef debug
    printf("%s\n", preOrdero);
#endif
    index = 0;
    midOrder(container, midOrdero, &index);
#ifdef debug
    printf("%s\n", midOrdero);
#endif

    for (int i = 0; i < n; i++) {
      std::cin >> origin;

      createTree();

      int index = 0;
      preOrder(container, preOrdertest, &index);
#ifdef debug
      printf("%s\n", preOrdertest);
#endif
      index = 0;
      midOrder(container, midOrdertest, &index);
#ifdef debug
      printf("%s\n", midOrdertest);
#endif
      if (strcmp(preOrdero, preOrdertest) == 0 &&
          strcmp(midOrdero, midOrdertest) == 0) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }
  return 0;
}
