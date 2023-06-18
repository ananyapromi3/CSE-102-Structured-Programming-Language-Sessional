#include<stdio.h>
int digitNum(unsigned int x)
{
    int n=0;
    while(x>>=1) n++;
    return n+1;
}
int main()
{
    unsigned int x;
    int temp, i, a=0, b=0;
    scanf("%ud",&x);
    int n=digitNum(x);
    for(i=n; i>=0; i-=2)
    {
        temp=(1<<i);
        temp=(temp&x);
        a=(a|temp);
        if(i!=0) a=(a>>1);
    }
    for(i=n-1; i>=0; i-=2)
    {
        temp=(1<<i);
        temp=(temp&x);
        b=(b|temp);
        if(i!=0) b=(b>>1);
    }
    if(a>b) printf("%d\n",a);
    else printf("%d\n",b);
    return 0;
}
