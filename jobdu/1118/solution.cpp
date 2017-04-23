#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//#define debug

int a, b;
char as[300];

int main() {
    while(scanf("%d%s%d", &a, as, &b) != EOF) {
        int length = strlen(as);
        long long int result10  = 0;
        for (int i = length - 1, aa = 1; i >= 0; i--) {
            int bit;
            if (as[i] >= '0' && as[i] <= '9') 
                bit = as[i] - '0';
            else if (as[i] >= 'a' && as[i] <= 'f')
                bit = as[i] - 'a' + 10;
            else if (as[i] >= 'A' && as[i] <= 'F')
                bit = as[i] - 'A' + 10;
            result10 += aa * bit;
            aa = aa * a;
        }
#ifdef debug
        printf("result10: %d \n", result10);
#endif
        
        char resultb[200];
        int sizeb = 0;
        do {
            char c;
            int y = result10 % b;
            result10 /= b;
            
            if (y >= 10) {
                c = 'A' + y - 10;
            } else {
                c = '0' + y;
            }
            resultb[sizeb++] = c;
        } while (result10 != 0);
        resultb[sizeb] = '\0';
        
#ifdef debug
        printf("resultb: %s \n", resultb);
#endif
        
        for (int i = sizeb - 1; i >= 0; i--) {
            printf("%c", resultb[i]);
        }
        printf("\n");
     }
     return 0;
}
