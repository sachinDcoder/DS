//A program to sort an array using heap sort
#include<stdio.h>
#include<stdlib.h>
void swap(int *p,int *q)
{
    int t;
    t=*p;
    *p=*q;
    *q=t;
}
void build_heap(int a[],int n)
{
    int c,p,i;
    for(i=1;i<n;i++)
    {
        c=i;
        while(c!=0)
        {
            p=(c-1)/2;
            if(a[p]<a[c])
                swap(&a[p],&a[c]);
            else
                break;
            c=p;
        }
    }
}
void heap_sort(int a[],int n)
{
    int i;
    build_heap(a,n);
    /*for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }*/
    for(i=n-1;i>=1;i--)
    {
        swap(&a[0],&a[i]);
        build_heap(a,i);
    }
}
int main()
{
    int n,i;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }
    printf("Your entered elements are : ");
    for(i=0;i<n;i++)
    {
        printf(" %5d",*(a+i));
    }
    heap_sort(a,n);
    printf("\nEnter any key to show the sorted list...");
    getch();
    printf("\nHeap sorted :");
    for(i=0;i<n;i++)
    {
        printf(" %5d",*(a+i));
    }
    return 0;
}


