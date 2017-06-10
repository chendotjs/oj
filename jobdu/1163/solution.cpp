#include <cstdio>
#include <cstring>

#define LENGTH 10010

int flag[LENGTH];

void prime() {
    memset(flag, 0, sizeof(flag));
    
    for (int i = 2; i < LENGTH; i++) {
        if (flag[i] == 1) continue;
        for (int j = i * i; j < LENGTH; j += i) {
            flag[j] = 1;
        }
    }
}


int main() {
    prime();
    int N;
    while (scanf("%d", &N) != EOF) {
        int firstTime = 1;  
        int noflag = 1;
        for (int i = 2; i < N; i++) {
            if (flag[i] == 0 && i % 10 == 1) {
                noflag = 0;
                if (firstTime) {
                    firstTime = 0;
                    printf("%d", i);
                }
                    
                else {
                    printf(" %d", i);
                }
            }
        }
        if (noflag) 
            printf("-1");
        printf("\n");
    }
    
}
