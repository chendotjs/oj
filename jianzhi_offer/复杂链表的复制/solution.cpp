#include <iostream>
#include <map>
using namespace std;

struct RandomListNode {
  int label;
  struct RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
  map<RandomListNode *, RandomListNode *> M;
  RandomListNode *Clone(RandomListNode *pHead) {
    RandomListNode *new_head;
    if (pHead == NULL)
      return NULL;

    new_head = new RandomListNode(pHead->label);
    M[pHead] = new_head;

    RandomListNode *p = pHead, *q = new_head, *r;
    while (p->next != NULL) {
      r = new RandomListNode(p->next->label);
      M[p->next] = r;
      q->next = r;
      p = p->next;
      q = q->next;
    }

    p = pHead;
    q = new_head;
    while (p != NULL) {
      if (p->random == NULL) {
        q->random = NULL;
      } else {
        q->random = M[p->random];
      }
      p = p->next;
      q = q->next;
    }

    return new_head;
  }
};

int main(int argc, char const *argv[]) {
  RandomListNode nodes[3] = {1, 2, 3};
  nodes[0].next = nodes + 1;
  nodes[1].next = nodes + 2;
  nodes[2].next = NULL;

  nodes[0].random = nodes + 2;
  nodes[1].random = nodes + 2;
  nodes[2].random = NULL;

  auto head = Solution().Clone(nodes);

  while (head != NULL) {
    printf("%p %d %p %p\n", head, head->label, head->next, head->random);
    head = head->next;
  }

  return 0;
}
