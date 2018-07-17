#include<stdio.h>
#include<malloc.h>
void merge_sort(int a[],int l,int u)
{
    int mid,i,j,k;
    if(l<=u)
    {
        int *b=(int*)malloc(sizeof(int)*(u-l+1));
        mid=(l+u)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,u);
        for(i=l,j=mid+1,k=l; i<=mid && j<=u ;k++)
        {
            if(a[i]<a[j])
                b[k]=a[i++];
            else
                b[k]=a[j++];
        }
        while(i<=mid)
            b[k++]=a[i++];
        while(j<=u)
            b[k++]=a[j++];
        for(k=l;k<=u;k++)
            a[k]=b[k];
    }
}
int main()
{
    int *a,i,n;
    printf("Enter the no. of elements you would enter : ");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    printf("Enter the elements :\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("You have entered : ");
    for(i=0;i<n;i++)
        printf("%4d",a[i]);
    printf("\nMerge sorted : ");
    merge_sort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%4d",a[i]);
}

