#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
    if (pHead1 == NULL || pHead2 == NULL)
      return NULL;

    stack<ListNode *> stack1, stack2;
    ListNode *result = NULL;

    while (pHead1 != NULL) {
      stack1.push(pHead1);
      pHead1 = pHead1->next;
    }

    while (pHead2 != NULL) {
      stack2.push(pHead2);
      pHead2 = pHead2->next;
    }

    while (stack1.empty() == false && stack2.empty() == false &&
           stack1.top() == stack2.top()) {
      result = stack1.top();
      stack1.pop();
      stack2.pop();
    }

    return result;
  }
};

int main() { return 0; }
