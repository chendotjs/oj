#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *deleteDuplication(ListNode *pHead) {
    if (!pHead)
      return pHead;
    ListNode *new_head = new ListNode(pHead->val - 1);
    new_head->next = pHead;

    ListNode *p = new_head, *q = pHead;

    while (q != NULL) {
      // printf("p: %d q %d\n", p->val, q->val);
      if (q->next == NULL) {
        p->next = q;
        break;
      }
      if (q->val != q->next->val) {
        p = p->next;
        q = q->next;
      } else {
        int val = q->val;
        while (q != NULL && q->val == val) {
          q = q->next;
        }
        p->next = q;
      }
    }
    return new_head->next;
  }
};

void print(ListNode *pHead) {
  while (pHead != NULL) {
    cout << pHead->val << "->";
    pHead = pHead->next;
  }
  cout << endl;
}

int main() {
  {
    ListNode nodes[] = {1, 1, 1};
    for (int i = 0; i < sizeof(nodes) / sizeof(struct ListNode); i++) {
      nodes[i].next = nodes + i + 1;
    }
    nodes[sizeof(nodes) / sizeof(struct ListNode) - 1].next = NULL;
    Solution s;
    print(s.deleteDuplication(nodes));
  }
  {
    ListNode nodes[] = {1, 2, 3, 3, 4, 4, 5};
    for (int i = 0; i < sizeof(nodes) / sizeof(struct ListNode); i++) {
      nodes[i].next = nodes + i + 1;
    }
    nodes[sizeof(nodes) / sizeof(struct ListNode) - 1].next = NULL;
    Solution s;
    print(s.deleteDuplication(nodes));
  }

  {
    ListNode nodes[] = {1, 1, 1, 1, 2, 3, 3, 4, 4, 5};
    for (int i = 0; i < sizeof(nodes) / sizeof(struct ListNode); i++) {
      nodes[i].next = nodes + i + 1;
    }
    nodes[sizeof(nodes) / sizeof(struct ListNode) - 1].next = NULL;
    Solution s;
    print(s.deleteDuplication(nodes));
  }

  {
    Solution s;
    print(s.deleteDuplication(NULL));
  }
}
