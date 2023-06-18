#include<stdio.h>
int main()
{
    int n, m, i, j, k, p, arr1[1000], arr2[1000], arr[2000];
    printf("Enter the number of elements of first array: ");
    scanf("%d",&n);
    printf("Enter the elements in non-decreasing order: ");
    for(i=0;i<n;i++) scanf("%d",&arr1[i]);
    printf("Enter the number of elements of second array: ");
    scanf("%d",&m);
    printf("Enter the elements in non-decreasing order: ");
    for(i=0;i<m;i++) scanf("%d",&arr2[i]);
    i=0;
    j=0;
    k=1;
    if(arr1[0]<arr2[0]) arr[0]=arr1[0];
    else arr[0]=arr2[0];
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            if(arr1[i]!=arr[k-1]) arr[k++]=arr1[i];
            i++;
        }
        else
        {
            if(arr2[j]!=arr[k-1]) arr[k++]=arr2[j];
            j++;
        }
    }
    for(p=i;p<n;p++) if(arr[k-1]!=arr1[p]) arr[k++]=arr1[p];
    for(p=j;p<m;p++) if(arr[k-1]!=arr2[p]) arr[k++]=arr2[p];
    printf("Final array: ");
    for(i=0;i<k;i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
