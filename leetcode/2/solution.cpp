#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
typedef struct ListNode ListNode;

typedef unsigned long long ULL;

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    int curr = 0;
    ListNode * ans = new ListNode(0);
    ListNode * ansp = ans;
    while (1) {
      curr = 0;
      if (l1 != NULL) {
        curr += l1->val;
        l1 = l1->next;
      }

      if (l2 != NULL) {
        curr += l2->val;
        l2 = l2->next;
      }
      curr += carry;
      ans->next = new ListNode(curr % 10);
      carry = curr / 10;
      ans = ans->next;

      if (l1 != NULL || l2 != NULL || carry != 0) {

      } else break;
    }
    return ansp->next;
  }
};

int main() {
  {
    ListNode list1[3] = {2, 4, 3};
    list1[0].next = list1 + 1;
    list1[1].next = list1 + 2;
    list1[2].next = NULL;

    ListNode list2[3] = {5, 6, 4};
    list2[0].next = list2 + 1;
    list2[1].next = list2 + 2;
    list2[2].next = NULL;

    Solution s;
    ListNode *ansp = s.addTwoNumbers(list1, list2);
    while (ansp != NULL) {
      printf("%d -> ", ansp->val);
      ansp = ansp->next;
    }
    printf("\n");
  }
  {
    ListNode list1[3] = {2, 4, 3};
    list1[0].next = list1 + 1;
    list1[1].next = list1 + 2;
    list1[2].next = NULL;

    ListNode list2[4] = {5, 6, 8, 1};
    list2[0].next = list2 + 1;
    list2[1].next = list2 + 2;
    list2[2].next = list2 + 3;
    list2[3].next = NULL;

    Solution s;
    ListNode *ansp = s.addTwoNumbers(list1, list2);
    while (ansp != NULL) {
      printf("%d -> ", ansp->val);
      ansp = ansp->next;
    }
    printf("\n");
  }

  {
    ListNode list1[1] = {0};
    list1[0].next = NULL;

    ListNode list2[3] = {5, 6, 4};
    list2[0].next = list2 + 1;
    list2[1].next = list2 + 2;
    list2[2].next = NULL;

    Solution s;
    ListNode *ansp = s.addTwoNumbers(list1, list2);
    while (ansp != NULL) {
      printf("%d -> ", ansp->val);
      ansp = ansp->next;
    }
    printf("\n");
  }

  {
    ListNode list1[1] = {0};
    list1[0].next = NULL;

    ListNode list2[1] = {0};
    list2[0].next = NULL;

    Solution s;
    ListNode *ansp = s.addTwoNumbers(list1, list2);
    while (ansp != NULL) {
      printf("%d -> ", ansp->val);
      ansp = ansp->next;
    }
    printf("\n");
  }

  return 0;
}
