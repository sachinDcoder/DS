#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int interpolation_search(int a[],int l,int h,int v)
{
    int m;
    while(l<=h)
    {
        m=l+(h-l)*((v-a[l])/(a[h]-a[l]));
        if(a[m]==v)
            return m;
        else if(v<a[m])
            h=m-1;
        else
            l=m+1;
    }
    return -1;
}
int main()
{
    int *a,n,i,v;
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("v = ");
    scanf("%d",&v);
    if(interpolation_search(a,0,n-1,v)!=-1)
        printf("\n%d",interpolation_search(a,0,n-1,v));
    else
        printf("\nValue doesn't exist in the array");
    return 0;
}
