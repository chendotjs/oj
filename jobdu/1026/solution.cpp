#include <cstdio>
using namespace std;

long long int K, A, B;

void solution(long long int result, int K) {
    char arr[100];
    int size = 0;
    if (result == 0) {
        printf("0");
        return;
    }
    while (result != 0) {
        long long int t = result % K;
        arr[size++] = t;
        result /= K;
    }
    for (int i = size - 1; i >= 0; i--) 
        printf("%d", arr[i]);
}

int main() {
    while (scanf("%lld", &K) != EOF && !(K == 0)) {
        scanf("%lld%lld", &A, &B);
        long long int result = A + B;
        solution(result, K);
        printf("\n");
    }
    return 0;
}
