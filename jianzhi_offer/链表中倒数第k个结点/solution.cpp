#include <cstdio>
#include <iostream>

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
    if (pListHead == NULL || k == 0)
      return nullptr;

    ListNode *ahead = pListHead;
    ListNode *behind = pListHead;
    for (int i = 0; i < k - 1; i++) {
      if (ahead->next != NULL) {
        ahead = ahead->next;
      } else
        return NULL;
    }

    while (ahead->next != NULL) {
      ahead = ahead->next;
      behind = behind->next;
    }
    return behind;
  }
};
