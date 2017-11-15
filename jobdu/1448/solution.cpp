#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define LENGTH 101

int indegree[LENGTH];
vector<int> edge[LENGTH];

int N, M;
int main() {
	while (scanf("%d%d", &N, &M) != EOF && N != 0) {
		for (int i = 0; i < LENGTH; i++) {
			edge[i].clear();
			indegree[i] = 0;
		}
		int cnt = 0;
		queue<int> que;
		
		int a, b;
		while (M--) {
			scanf("%d%d", &a, &b);
			indegree[a]++;
			edge[b].push_back(a);
		}
		for (int i = 0; i < N; i++) {
			if (indegree[i] == 0) que.push(i);
		}
		
		while (que.empty() == false) {
			int rmnode = que.front();
			que.pop();
			cnt++;
			
			for (int i = 0; i < edge[rmnode].size(); i++) {
				indegree[edge[rmnode][i]]--;
				if (indegree[edge[rmnode][i]] == 0)
					que.push(edge[rmnode][i]);
			}
		}
		if (cnt == N)
			printf("YES\n");
		else 
			printf("NO\n");
	} 
	return 0;
}
