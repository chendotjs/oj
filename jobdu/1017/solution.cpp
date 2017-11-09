#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LENGTH 6000
int N;
int L;
int root[LENGTH];
int cnt[LENGTH];  // num of this set

struct Edge {
 int a;
 int b;
 int dis;
};

bool ecmp(const struct Edge& e1, const struct Edge& e2) {
	return e1.dis <= e2.dis;
}

struct Edge edge[LENGTH];

void init() {
	for (int i = 0; i < LENGTH; i++) {
		root[i] = i;
		cnt[i] = 1;
	}
	memset(edge, 0, sizeof(edge));
}

int findRoot(int x) {
	int ret;
	int tmp  = x;
	while (root[x] != x)
		x = root[x];
	ret = x;
	x = tmp;
	while (root[x] != x) {
		int y = root[x];
		root[x] = ret;
		x = y;
	}
	return ret;
}



int main() {
	while (scanf("%d", &N) != EOF && N != 0) {
		init();
		L = N * (N - 1) / 2;
		for (int i = 0; i < L; i++) {
			scanf("%d%d%d", &(edge[i].a), &(edge[i].b), &(edge[i].dis));
		}
		std::sort(edge, edge + L, ecmp);
		
		long long int ans = 0;
		for (int i = 0; i < L; i++) {
			int ra = findRoot(edge[i].a);
			int rb = findRoot(edge[i].b);
			// printf("%d %d\n", ra, rb);
			if (ra != rb) {
				ans += edge[i].dis;
				root[ra] = rb;
				cnt[rb] += cnt[ra];
				if (cnt[rb] >= N)
					break;
			}
		}
		printf("%lld\n", ans);
	}
}
