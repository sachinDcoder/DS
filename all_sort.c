#include<stdio.h>
#include<malloc.h>
void swap(int *p,int *q)
{
    int t;
    t=*p;
    *p=*q;
    *q=t;
}
void bubble_sort(int a[],int n)
{
    int i,j,f;
    for(f=1,i=1;i<n && f==1;i++)
        for(f=0,j=0;j<=n-i;j++)
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
                f=1;
            }
}
void selection_sort(int a[],int n)
{
    int i,j,min,p;
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        for(j=i+1;j<=n-1;j++)
        {
            if(min > a[j])
            {
                min=a[j];
                p=j;
                a[p]=a[i];
                a[i]=min;
            }
        }
    }
}
void quick_sort(int a[],int x,int y)
{
    int p=a[x];
    int d=x,u=y;
    while(d<u)
    {
        while(a[u]>p && u>=x)
            u--;
        while(a[d]<=p && d<=y)
            d++;
        if(d<u)
            swap(&a[d],&a[u]);
    }
    a[x]=a[u];
    a[u]=p;
    if(u>x)
        quick_sort(a,x,u-1);
    if(y>u)
        quick_sort(a,u+1,y);
}
void insertion_sort(int a[],int n)
{
    int i,j,z;
    for(i=1;i<n;i++)
    {
        z=a[i];
        for(j=i-1;j>=0 && z<a[j];j--)
            a[j+1]=a[j];
        a[j+1]=z;
    }
}
int bSearch(int a[],int low,int high,int item)
{
    if (high <= low)
        return (item > a[low])?  (low + 1): low;

    int mid = (low + high)/2;

    if(item == a[mid])
        return mid+1;

    if(item > a[mid])
        return bSearch(a, mid+1, high, item);
    else
        return bSearch(a, low, mid-1, item);
}
void insertion_sort_bSearch(int a[],int n)
{
    int i,j,z,p;
    for(i=1;i<n;i++)
    {
        z=a[i];
        p=bSearch(a,0,i-1,z);
        for(j=0;j<=p+1;j++)
            a[j+1]=a[j];
        a[j+1]=z;
    }
}
int main()
{
    int i,*a,n,*b,*c,*d,*e;
    printf("Enter the Size of array for bubble sort : ");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    printf("Enter your elements \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("You have entered : ");
    for(i=0;i<n;i++)
        printf("%4d",a[i]);
    printf("\nBubble sort : ");
    bubble_sort(a,n);
    for(i=0;i<n;i++)
        printf("%4d",a[i]);
    printf("\n\nEnter the Size of array for selection sort : ");
    scanf("%d",&n);
    b=(int *)malloc(sizeof(int)*n);
    printf("Enter your elements \n");
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    printf("You have entered : ");
    for(i=0;i<n;i++)
        printf("%4d",b[i]);
    printf("\nSelection sort : ");
    selection_sort(b,n);
    for(i=0;i<n;i++)
        printf("%4d",b[i]);
    printf("\n\nEnter the Size of array for quick sort : ");
    scanf("%d",&n);
    c=(int *)malloc(sizeof(int)*n);
    printf("Enter your elements \n");
    for(i=0;i<n;i++)
        scanf("%d",&c[i]);
    printf("You have entered : ");
    for(i=0;i<n;i++)
        printf("%4d",c[i]);
    quick_sort(c,0,n-1);
    printf("\nQuick sort : ");
    for(i=0;i<n;i++)
        printf("%4d",c[i]);
    printf("\n\nEnter the Size of array for insertion sort using linear search : ");
    scanf("%d",&n);
    d=(int *)malloc(sizeof(int)*n);
    printf("Enter your elements \n");
    for(i=0;i<n;i++)
        scanf("%d",&d[i]);
    printf("You have entered : ");
    for(i=0;i<n;i++)
        printf("%4d",d[i]);
    insertion_sort(d,n);
    printf("\nInsertion sort : ");
    for(i=0;i<n;i++)
        printf("%4d",d[i]);
    printf("\n\nEnter the Size of array for insertion sort using binary search : ");
    scanf("%d",&n);
    e=(int *)malloc(sizeof(int)*n);
    printf("Enter your elements \n");
    for(i=0;i<n;i++)
        scanf("%d",&e[i]);
    printf("You have entered : ");
    for(i=0;i<n;i++)
        printf("%4d",e[i]);
    insertion_sort_bSearch(e,n);
    printf("\nInsertion sort : ");
    for(i=0;i<n;i++)
        printf("%4d",e[i]);
    return 0;
}



