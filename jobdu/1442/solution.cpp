// https://www.nowcoder.com/practice/b2b34f77d9ca44e4ae042185bdacb16e?tpId=43&&tqId=26113&rp=1&ru=/activity/oj&qru=/ta/acm-training/question-ranking

#include <cstdio>

int N;

long long arith(long long a, long long d, long long k) {
  long long ans = (a % 200907) + (((k - 1) % 200907) * (d % 200907)) % 200907;
  return ans % 200907;
}

long long geo(long long a, long long m, long long k) {
  long long ans = 1;
  k--;
  while (k != 0) {
    if (k & 0x01 == 1) {
      ans *= m;
      ans %= 200907;
    }
    k = k >> 1;
    m *= m;
    m %= 200907;
  }
  return (ans * (a % 200907)) % 200907;
}

int main() {
  scanf("%d", &N);
  long long a, b, c, k;
  long long int ans;
  for (int i = 0; i < N; i++) {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &k);
    if (a + c == b + b)
      ans = arith(a, b - a, k);
    else
      ans = geo(a, b / a, k);
    printf("%lld\n", ans);
  }

  return 0;
}
