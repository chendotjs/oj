#include <iostream>

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode *EntryNodeOfLoop(ListNode *pHead) {
    int circle;
    ListNode *meet = meetNode(pHead, circle);
    if (!meet)
      return NULL;
    ListNode *p1 = pHead;
    ListNode *p2 = pHead;
    for (int i = 0; i < circle; i++) {
      p1 = p1->next;
    }
    while (p1 != p2) {
      p1 = p1->next;
      p2 = p2->next;
    }
    return p1;
  }
  ListNode *meetNode(ListNode *pHead, int &circleLength) {
    if (pHead == NULL)
      return NULL;
    ListNode *slow = pHead;
    ListNode *quick = pHead;

    circleLength = 0;

    while (slow->next != NULL && quick->next != NULL) {
      slow = slow->next;
      quick = quick->next;
      quick = quick->next;
      circleLength++;
      if (slow == quick) {
        return slow;
      }
    }
    return NULL;
  }
};

int main(int argc, char const *argv[]) {
  ListNode nodes[] = {1, 2, 3, 4, 5, 6};
  for (int i = 0; i < sizeof(nodes) / sizeof(struct ListNode); i++) {
    nodes[i].next = nodes + i + 1;
  }
  nodes[sizeof(nodes) / sizeof(struct ListNode) - 1].next = nodes + 2;

  Solution s;
  ListNode *result = s.EntryNodeOfLoop(nodes);
  return 0;
}
