#include <iostream>
#include <cstdio>

//#define debug

typedef struct Node {
    int value;
    Node *lchild;
    Node *rchild;
} Node;

Node node[120];

int nodeCnt = 0;

Node* createNode(int v) {
    node[nodeCnt].value = v;
    node[nodeCnt].lchild = node[nodeCnt].rchild = NULL;
    nodeCnt++;
    return node + nodeCnt - 1;
}

void appendNode(Node* pcurr, Node* proot) {
    if (pcurr->value == proot->value)
        return;
    if (pcurr->value < proot->value) {
        if (proot->lchild == NULL) {
            proot->lchild = pcurr;
            return;
        } else {
            appendNode(pcurr, proot->lchild);
        }
    } else {
        if (proot->rchild == NULL) {
            proot->rchild = pcurr;
            return;
        } else {
            appendNode(pcurr, proot->rchild);
        }
    }
}

void preOrder(Node *root) {
    if (!root) return;
    printf("%d ", root->value);
    preOrder(root->lchild);
    preOrder(root->rchild);
}


void midOrder(Node *root) {
    if (!root) return;
    midOrder(root->lchild);
    printf("%d ", root->value);
    midOrder(root->rchild);
}


void postOrder(Node *root) {
    if (!root) return;    
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d ", root->value);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        nodeCnt = 0;
        int v;
        scanf("%d", &v);
        createNode(v);
        for(int i = 0; i < n - 1; i++) {
            scanf("%d", &v);
            Node *pnode = createNode(v);
            // append node
            appendNode(pnode, node);
#ifdef debug
            for (int i = 0; i < nodeCnt; i++) {
                printf("%dst: %d %ld %ld %ld\n", i, node[i].value, node + i,
node[i].lchild, node[i].rchild);
            }
#endif
        }
        preOrder(node);
        printf("\n");
        midOrder(node);
        printf("\n");
        postOrder(node);
        printf("\n");
    }
}
