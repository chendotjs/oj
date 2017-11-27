#include <iostream>
#include <cstdio>

using namespace std;

long long int arr[100];

int main()
{
    int n;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 2;
    arr[4] = 9;
    for (int i = 5; i <= 21; i++)
    {
        arr[i] = (i - 1) * (arr[i - 1] + arr[i - 2]);
    }
    while (scanf("%d", &n) != EOF)
    {
        printf("%lld\n", arr[n]);
    }
    return 0;
}

