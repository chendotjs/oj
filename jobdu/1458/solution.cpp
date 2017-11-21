#include <cstdio>

#define LENGTH
long long int ans[36];
int N;

int main() {
	ans[1] = 2;
	for (int i = 2; i <= 35; i++) {
		ans[i] = 3 * ans[i - 1] + 2;
	}
	
	while (scanf("%d", &N) != EOF) {
		printf("%lld\n", ans[N]);
	}
}
