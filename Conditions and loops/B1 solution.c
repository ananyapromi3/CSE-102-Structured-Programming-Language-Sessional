#include <stdio.h>
int main()
{
    int n, i;
    scanf("%d", &n);
    int ans = 1;
    int num_int = (n/3)*2;
    for(i=1;i<n;i++) ans*=3;
    if(n%3==1)
    {
        num_int++;
        printf("%dth term: %d\n", n, ans);
    }
    else if (n%3==2)
    {
        num_int++;
        printf("%dth term: %d/2\n", n, ans);
    }
    else
    {
        printf("%dth term: %d/3\n", n, ans);
    }
    printf("There are %d integers among the first %d terms\n", num_int, n);
    return 0;
}

