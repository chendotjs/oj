#include <iostream>
using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *merge) {
  while (merge != NULL) {
    cout << merge->val << " ";
    merge = merge->next;
  }
  cout << endl;
}

class Solution {
public:
  ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
    if (pHead1 == NULL)
      return pHead2;
    if (pHead2 == NULL)
      return pHead1;

    ListNode *p1 = pHead1;
    ListNode *p2 = pHead2;
    ListNode *pMerge = NULL;
    ListNode *pcur = NULL;

    while (p1 != NULL && p2 != NULL) {
      if (p1->val <= p2->val) {
        if (pMerge == NULL) {
          pMerge = pcur = pHead1;
          p1 = p1->next;
        } else {
          pcur->next = p1;
          p1 = p1->next;
          pcur = pcur->next;
        }
      } else {
        if (p2->val <= p1->val) {
          if (pMerge == NULL) {
            pMerge = pcur = pHead2;
            p2 = p2->next;
          } else {
            pcur->next = p2;
            p2 = p2->next;
            pcur = pcur->next;
          }
        }
      }
      // print(pMerge);
    }
    if (p1 != NULL) {
      pcur->next = p1;
    }
    if (p2 != NULL) {
      pcur->next = p2;
    }
    return pMerge;
  }
};

int main(int argc, char const *argv[]) {
  {
    ListNode nodes1[] = {1, 2, 3, 3, 4, 4, 5};
    for (int i = 0; i < sizeof(nodes1) / sizeof(struct ListNode); i++) {
      nodes1[i].next = nodes1 + i + 1;
    }
    nodes1[sizeof(nodes1) / sizeof(struct ListNode) - 1].next = NULL;

    ListNode nodes2[] = {1, 2, 3, 3, 4, 4, 5};
    for (int i = 0; i < sizeof(nodes2) / sizeof(struct ListNode); i++) {
      nodes2[i].next = nodes2 + i + 1;
    }
    nodes2[sizeof(nodes2) / sizeof(struct ListNode) - 1].next = NULL;

    ListNode *merge = Solution().Merge(nodes1, nodes2);
    print(merge);
  }

  return 0;
}
