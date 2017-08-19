#include <cstdio>
#include <cstring>
using namespace std;

#define DEBUG 0
#define LENGTH 100001

bool isPrime[LENGTH];
int prime[LENGTH];
int primeCnt = 0;

void calcPrime() {
    memset(isPrime, 1, sizeof(isPrime));
    for (int i = 2; i < LENGTH; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j >= 0 && j < LENGTH; j += i) {
                isPrime[j] = 0;
            }
        } 
    }
    for (int i = 2; i < LENGTH; i++) {
        if (isPrime[i]) {
            prime[primeCnt++] = i;
#if DEBUG
            printf("%d\n", i); 
#endif
        }
    }
}

int solution(int n) {
    int cnt = 0;
    for (int i = 0; i < primeCnt; i++) {
        while (n % prime[i] == 0) {
            n /=  prime[i];
            cnt++;
#if DEBUG
            printf("%d\n", prime[i]);
#endif
        }
        if (n == 1) 
            return cnt;
    }
    // 还有一个大于10^5的质因数
#if DEBUG
    printf("%d\n", n);
#endif
    cnt++;
    return cnt;
}

int main () {
    calcPrime();
    int n;
    while (scanf("%d", &n) != EOF) {
        int ans = solution(n);
        printf("%d\n", ans); 
    }
    return 0;
}
