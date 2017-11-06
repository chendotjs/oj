#include <cstdio>
#include <cstring>

using namespace std;


int N, M;
int root[1010];
int flag[1010];

int findRoot(int x) {
	int t = x;
	while (root[x] != x) {
		t = root[x];
		x = t;
	}
	// reduce path
	int y;
	while (root[x] != x) {
		y = root[x];
		root[x] = t;
		x = y;
	}
	return t;
}

int main() {
	while (scanf("%d", &N) != EOF && N != 0) {
		scanf("%d", &M);
		for (int i = 0; i < 1010; i++) 
			root[i] = i;
		while (M--) {
			int a, b;
			scanf("%d%d", &a, &b);
			int ra = findRoot(a);
			int rb = findRoot(b);
			if (ra != rb) {
				root[ra] = rb;
			}
		}
		// flag
		memset(flag, 0, sizeof(flag));
		for (int i = 1; i <= N; i++) {
			flag[findRoot(i)] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= N; i++)
			if (flag[i])
				ans++;
		printf("%d\n", ans - 1);
	}
	return 0;
}
