/**
 * https://www.nowcoder.com/questionTerminal/8e29045de1c84d349b43fdb123ab586a
 */

#include <cstdio>
#include <cstring>
#include <iostream>

#define LENGTH 1010

int mark[LENGTH];
int prime[LENGTH];
int primeCnt = 0;

void initPrime() {
  memset(mark, 0, LENGTH * sizeof(int));
  for (int i = 2; i < LENGTH; i++) {
    if (mark[i] == 0)
      for (int j = i * i; j < LENGTH; j += i) {
        mark[j] = 1;
      }
  }
  for (int i = 2; i < LENGTH; i++) {
		if (mark[i] == 0) {
			prime[primeCnt++] = i;
			//printf("%d\n", i);
		}
		
	}
}

int cnta[LENGTH];
int cntn[LENGTH];

int main(int argc, char const *argv[]) { 
	int n, a;
	initPrime();
	while (scanf("%d%d", &n, &a) != EOF) {
		//init cnt
		memset(cnta, 0, sizeof(cnta));
		memset(cntn, 0, sizeof(cntn));
			
		//extract a
		int aa = a;
		for (int i = 0; i < primeCnt; i++) {
			while (aa % prime[i] == 0) {
				aa /= prime[i];
				cnta[i]++;
			}
		}
		//extract n!
		for (int i = 0; i < primeCnt; i++) {
			int p = prime[i];
			while (n / p > 0) {
				cntn[i] += n / p;
				p *= prime[i];
			}
		}
		
		int ans = 100000;
		for (int i = 0; i < primeCnt; i++) {
			if (cnta[i] != 0) {
				ans = cntn[i] / cnta[i] < ans ? cntn[i] / cnta[i] : ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0; 
}
