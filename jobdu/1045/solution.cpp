#include <cstdio>

using namespace std;

int n;
int main() {
	while (scanf("%d", &n) != EOF) {
		long int N = 3 * n;
		for (int i = 0; i <= n / 5; i++) {
			for (int j = 0; j <= n / 3; j++) {
				int z = 100 - i - j;
				if (15 * i + 9 * j + z <= N) {
					printf("x=%d,y=%d,z=%d\n", i, j, z);
				}					
			}
		}
	}
}
