// https://www.nowcoder.com/practice/35e89a747168442096f18cc0e20b54da?tpId=43&&tqId=27074&rp=1&ru=/activity/oj&qru=/ta/acm-training/question-ranking
#include <cstdio>

int main() {
	int a, b;
	int ans;
	while (scanf("%d%d", &a, &b) != EOF) {
		if (a == 0 && b == 0) break;
		ans = 1;
		int ap = a;
		while (b != 0) {
			if (b & 0x01 == 1) {
				ans *= ap;
				ans = ans % 1000;
			}				
			b = b >> 1;
			ap *= ap;
			ap = ap % 1000;
		}
		printf("%d\n", ans);
	}
}
