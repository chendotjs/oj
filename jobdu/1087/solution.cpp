// https://www.nowcoder.com/practice/04c8a5ea209d41798d23b59f053fa4d6?tpId=40&&tqId=21334&rp=1&ru=/activity/oj&qru=/ta/kaoyan/question-ranking


#include <stdio.h>
#include <string.h>

#define LENGTH 100010

int prime[LENGTH];
int mark[LENGTH];
int primeSize = 0;

int cnt[LENGTH];

void initPrime() {
	memset(mark, 0, sizeof(mark));
	for (int i = 2; i < LENGTH; i++) {
		if (mark[i] == 0) {
			for (int j = i * i; j >= 0 && j < LENGTH; j += i) {
				mark[j] = 1;
			}
		}
	}
	for (int i = 2; i < LENGTH; i++) {
		if (mark[i] == 0) {
			prime[primeSize++] = i;
			// printf("%d\n", i);
		}
	}
}

int solution(int num) {
	int n = num;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < primeSize; i++) {
		while (num % prime[i] == 0) {
			cnt[i]++;
			num /= prime[i];
		}
	}
	int ans = 1;
	for (int i = 0; i < primeSize; i++) {
		if (prime[i] > n)
			break;
		ans *= (cnt[i] + 1);
	}
	if (num != 1)
		ans *= 2;
	return ans;
}

int main() {
	int N;
	int num;
	initPrime();
	while (scanf("%d", &N) != EOF && N != 0) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &num);
			printf("%d\n", solution(num));
		}
	}
	
	return 0;
}
