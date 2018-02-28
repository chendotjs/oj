#include <iostream>
using namespace std;
struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode *ReverseList(ListNode *pHead) {
    if (pHead == NULL)
      return NULL;
    ListNode *p, *q, *r;
    p = pHead;
    q = p->next;
    while (q != NULL) {
      r = q->next;
      q->next = p;
      p = q;
      q = r;
    }
    pHead->next = NULL;
    return p;
  }
};

int main(int argc, char const *argv[]) {
  {
    ListNode nodes[] = {1};
    ListNode *head = Solution().ReverseList(nodes);
    while (head != NULL) {
      cout << head->val << " ";
      head = head->next;
    }
    cout << endl;
  }

  {
    ListNode nodes[] = {1, 2, 3};
    nodes[0].next = nodes + 1;
    nodes[1].next = nodes + 2;
    ListNode *head = Solution().ReverseList(nodes);
    while (head != NULL) {
      cout << head->val << " ";
      head = head->next;
    }
    cout << endl;
  }

  return 0;
}
