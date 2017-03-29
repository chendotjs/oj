#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
#define LENGH 50003
/**
堆可以看作一个完全二叉树，为了避免复杂的指针操作，可以使用数组来模拟二叉堆。
*/

class MinHeap {
public:
  long heap[LENGH];
  long length;

  void heap_add(long item) {
    heap[length++] = item;
    //向上调整
    long current = length - 1;
    long parent = (current + 1) / 2 - 1;
    while (current >= 0 && parent >= 0 && heap[current] < heap[parent]) {
      //交换
      long tmp = heap[current];
      heap[current] = heap[parent];
      heap[parent] = tmp;

      current = parent;
      parent = (current + 1) / 2 - 1;
    }
  }

  bool heap_delete(long &top) {
    if (length > 0)
      top = heap[0];
    else
      return false;
    length--;
    heap[0] = heap[length];
    //向下调整
    long current = 0;
    long child = current * 2 + 1;
    while (current < length && child < length) {
      if (child + 1 < length && heap[child + 1] < heap[child])
        child++;
      if (heap[current] <= heap[child])
        break;
      //交换
      // printf("exchage %ld %ld, %ld, %ld\n", heap[current], heap[child],
      // current, child);
      long tmp = heap[current];
      heap[current] = heap[child];
      heap[child] = tmp;

      current = child;
      child = current * 2 + 1;
    }
    return true;
  }

  void print() {
    for (long i = 0; i < this->length; i++) {
      printf("%ld ", this->heap[i]);
    }
    printf("\n");
  }
  MinHeap() { length = 0; }
};

int main() {
  long num;
  while (scanf("%ld", &num) != EOF) {
    MinHeap mh;
    for (long i = 0; i < num; i++) {
      long n;
      scanf("%ld", &n);
      mh.heap_add(n);
    }
    // mh.print();

    long top;
    for (long i = 0; i < num; i++) {
      mh.heap_delete(top);
      printf("%ld ", top);
      // mh.print();
    }
    printf("\n");
  }
}
