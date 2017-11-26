#include <iostream>
#include <cstdio>

using namespace std;

/**
  1 2 3 4 5
  1 2 3 5
**/

int N;
long int steps[100];
int main()
{
  steps[1] = 1;
  steps[2] = 2;
  for (int i = 3; i <= 91; i++) {
    steps[i] = steps[i - 1] + steps[i - 2];
    //printf("%ld\n", steps[i]);
  }
  while (scanf("%d", &N) != EOF) {
    printf("%ld\n", steps[N]);
  }
  return 0;
}

