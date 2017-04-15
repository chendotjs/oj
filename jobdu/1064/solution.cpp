#include <cstdio>
#include <cstring>
using namespace std;

int reverse(int num) {
  int arr[100];
  memset(arr, 0, sizeof(arr));
  int size = 0;
  while (num > 0) {
    int yushu = num % 10;
    arr[size++] = yushu;
    num /= 10;
  }
  int re = 0;
  for(int i = size - 1, base = 1; i >= 0; i--) {
    re += arr[i] * base;
    base *= 10;
  }
  return re;
}

int main() {
  int num = 1088;
  for (int i = num; i < 1090; i++) {
    // printf("%d %d\n", i, reverse(i));
    if(i * 9  == reverse(i)) {
      printf("%d\n", i);
    }
  }
  return 0;
}
