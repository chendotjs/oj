#include <cstdio>
#include <cmath>


bool judge(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    
    for (int i = 2; i <= sqrt(num) + 1; i++) {
        if (num % i == 0) 
            return false;
    }
    return true;
}

int main() {
    int num;
    while (scanf("%d", &num) != EOF) {
        if (judge(num)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}
