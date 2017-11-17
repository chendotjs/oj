#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define LENGTH 50

int maze[LENGTH][LENGTH][LENGTH];
bool mark[LENGTH][LENGTH][LENGTH];

struct N {
	int x, y, z, t;
};

queue<struct N> Q;

int go[][3] = {
	{-1, 0, 0},
	{1, 0, 0},
	{0, -1, 0}, 
	{0, 1 ,0},
	{0, 0, -1},
	{0, 0, 1}
};

int BFS(int a, int b, int c) {
	mark[0][0][0] = true;
	struct N tmp = {0, 0, 0, 0};
	Q.push(tmp);
	
	while (Q.empty() == false) {
		struct N now = Q.front();
		Q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = go[i][0] + now.x;
			int ny = go[i][1] + now.y;
			int nz = go[i][2] + now.z;
			if (nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c) continue;
			if (maze[nx][ny][nz] == 1) continue;
			if (mark[nx][ny][nz] == true) continue;
			struct N tmp = {nx, ny, nz, now.t + 1};
			Q.push(tmp);
			mark[nx][ny][nz] = true;
			if (nx == a - 1 && ny == b - 1 && nz == c - 1)
				return tmp.t;
		}
	}
	return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int A, B, C, t;
		scanf("%d%d%d%d" ,&A, &B, &C, &t);
		//memset(mark, 0, sizeof(mark));
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				for (int k = 0; k < C; k++) {
					scanf("%d", &maze[i][j][k]);
					mark[i][j][k] = false;
				}
			}
		}
		
		while (Q.empty() == false) Q.pop();
		int ret = BFS(A, B, C);
		int result = ret <= t ? ret : -1;
		printf("%d\n", result);
	}
	
	return 0;
}
