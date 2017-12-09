#include <cstdio>
#include <cstring>
using namespace std;

#define LENGTH 5000

char str1[LENGTH];
char str2[LENGTH];

char num1[LENGTH];
char num2[LENGTH];
char ans[LENGTH];

int main(int argc, char const *argv[]) {
  // freopen("in.txt", "r", stdin);
  while (scanf("%s%s", str1, str2) != EOF) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    memset(num1, 0, sizeof(num1));
    memset(num2, 0, sizeof(num2));
    for (int i = len1 - 1, j = 0; i >= 0; i--) {
      num1[j++] = str1[i] - '0';
    }
    for (int i = len2 - 1, j = 0; i >= 0; i--) {
      num2[j++] = str2[i] - '0';
    }
    int anssize = 0;
    int carry = 0;
    int maxsize = len1 > len2 ? len1 : len2;
    for (int i = 0; i < maxsize; i++) {
      int a = num1[i];
      int b = num2[i];
      int tmp = (a + b + carry);
      ans[anssize++] = tmp % 10;
      carry = tmp / 10;
    }
    if (carry) {
      ans[anssize++] = carry;
    }
    for (int i = anssize - 1; i >= 0; i--) {
      printf("%c", ans[i] + '0');
    }
    printf("\n");
  }
  return 0;
}
